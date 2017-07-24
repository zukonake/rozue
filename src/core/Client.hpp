#pragma once

#include <network/common.hpp>
#include <network/ColdSocket.hpp>
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
class Client : SFMLClient, public network::ColdSocket
{
public:
	Client( Nickname const &nickname );

	virtual void send( network::Data const &datagram ) override;
	virtual network::Data receive() override;

	Nickname getNickname();
private:
	void parseServerData( ServerData const &serverData );

	Nickname mNickname;
	network::ColdSocket mSocket;
	Dataset mDataset;
};
