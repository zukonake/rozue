#pragma once

#include <network/common.hpp>
#include <network/ColdSocket.hpp>
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
class Client : SFMLClient, public network::ColdSocket
{
public:
	ClientData requestClientData();
	void receiveServerData( ServerData const &serverData );
private:
	void parseServerData( ServerData const &serverData );

	Dataset mDataset;
};
