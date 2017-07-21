#pragma once

#include <network/common.hpp>
#include <core/common.hpp>
#include <core/SFMLClient.hpp>
#include <data/Dataset.hpp>

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
	Client( ID const &ID );

	ClientData requestClientData();
	void receiveServerData( ServerData const &serverData );

	void connectTo( network::IP const &IPAddress, network::Port const &port );
	void disconnect();

	bool isConnected() const noexcept;
	ID const &getID() const noexcept;
private:
	void parseServerData( ServerData const &serverData );

	ID mID;
	Dataset mDataset;
};
