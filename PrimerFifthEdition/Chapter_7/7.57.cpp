#include <iostream>

using std::cout;

class Account
{
public:
    void calculate()
    {
        amount += amount * interestRate;
    }
    static double rate()
    {
        return interestRate;
    }
    static void rate(double);

private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate()
    {
        return 20;
    };

    static constexpr int period = 30;
    double daily_tbl[period];
};

double Account::interestRate = initRate();

void Account::rate(double newRate)
{
    interestRate = newRate;
}

int main()
{
    Account a;
    Account::rate(292);
    cout << a.rate();

    return 0;
}
