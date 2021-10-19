#include <future>
#include <mutex>
#include <queue>
#include <vector>

using Connection = std::vector<int>;
using ConnectionSet = std::vector<Connection>;

void processConnections(ConnectionSet& connections)
{
    while (true)
    {
        for (auto& connection : connections)
        {
            if (connection.hasIncomingData())
            {
                dataPacket data = connection.incoming();
                connection.getPromise(data.id).setValue(data.payload);
            }
            if (connection.hasOutgoingData())
            {
                OutgoingPacket data = connection.top();
                connection.send(data.payload);
                data.promise.setValue(true);
            }
        }
    }
}
