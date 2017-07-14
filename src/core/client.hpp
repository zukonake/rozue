#pragma once

#include <core/network.hpp>
#include <core/SFMLClient.hpp>
#include <data/dataset.hpp>

class Server;
struct ClientData;
struct ServerData;

/*TODO
 *have autonomous thread which renders until next data is received
 *networking stuff( ip etc. )
 *render only differences from previous data
 */

/**
 * Client is responsible for preparing ClientData and parsing ServerData.
 */
class Client : SFMLClient
{
public:
	Client( Network::ID const &ID );

	ClientData requestClientData();
	void receiveServerData( ServerData const &serverData );

	void connectTo( Network::IP const &IPAddress, Network::Port const &port );
	void disconnect();

	bool isConnected() const noexcept;
	Network::ID const &getID() const noexcept;
private:
	void parseServerData( ServerData const &serverData );

	Network::ID mID;
	Network::TCPSocket mSocket;

	Dataset mDataset;
};
