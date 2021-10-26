#include <string>

struct card_inserted
{
    std::string account;
};
class atm
{
public:
    void run()
    {
        state = &atm::waiting_for_card;
        try
        {
            for (;;)
            {
                (this->*state)();
            }
        }
        catch (const messaging::clase_queue& err)
        {
        }
    }

private:
    messaging::receiver incoming;
    messaging::sender bank;
    messaging::sender interface_hardware;
    void (atm::*state)();

    std::string account;
    std::string pin;

    void waiting_for_card()
    {
        interface_hardware.send(display_enter_card());
        incoming.wait().handle<card_inserted>(
            [&](const card_inserted& msg)
            {
                account = msg.account;
                pin = "";
                interface_hardware.send(display_enter_pin());
                state = &atm::getting_pin;
            });
    }

    void getting_pin()
    {
        incoming
            .wait() // 链接方法，handle只能处理这三种消息，其他的消息都会被丢弃
            .handle<digit_pressed>(
                [&](const digit_pressed& msg)
                {
                    unsigned const pin_length = 4;
                    pin += msg.digit;
                    if (pin.length() == pin_length)
                    {
                        bank.send(verify_pin(account, pin, incoming));
                        state = &atm::verify_pin;
                    }
                })
            .handle<clear_last_pressed>(
                [&](const clear_last_pressed& msg)
                {
                    if (!pin.empty())
                    {
                        pin.resize(pin.length() - 1);
                    }
                })
            .handle<cancel_pressed>([&](const cancel_pressed& msg) { state = &atm::waiting_for_card; });
    }
};
