#pragma once

#include <memory>
//
#include <core/network.hpp>
#include <core/player.hpp>

class Client;

/**
 * Connection manages the data flow between the Client and the Server.
 */
class Connection
{
public:
	Connection( std::unique_ptr< Network::TCPSocket > socket, std::unique_ptr< Player > player );

	/**
	 * This funtion exchanges ClientData and ServerData between Client and Player.
	 */
	void exchangeData();
	void disconnect();
private:
	std::unique_ptr< Network::TCPSocket > mSocket;
	std::unique_ptr< Player > mPlayer;
};
