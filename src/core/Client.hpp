#pragma once

#include <network/common.hpp>
#include <network/cold/Socket.hpp>
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
class Client : SFMLClient, public network::cold::Socket
{
public:
	Client( Nickname const &nickname );

	void connectTo( network::IP address, network::Port port );

	void send();
	ServerData receive();

	Nickname getNickname();
private:
	void parseServerData( ServerData const &serverData );

	Nickname mNickname;
	network::cold::Socket mSocket;
	Dataset mDataset;
};
