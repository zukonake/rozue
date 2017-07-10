#pragma once

#include <core/typedef.hpp>
#include <core/SFMLClient.hpp>
#include <data/dataset.hpp>

class Server;
class ClientData;
class ServerData;

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
	Client( ClientID const &clientID );

	ClientData requestClientData();
	void receiveServerData( ServerData const &serverData );

	void connectTo( Server &server );
	void disconnect();

	bool const &isConnected() const noexcept;
	ClientID const &getID() const noexcept;
private:
	void parseServerData( ServerData const &serverData );

	bool mConnected;
	ClientID mID;
	Dataset mDataset;
	Server *mServer;
};
