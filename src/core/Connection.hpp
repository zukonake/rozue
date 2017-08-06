#pragma once

#include <memory>
//
#include <network/udp/Socket.hpp>
#include <core/Player.hpp>

class Client;

/**
 * Connection manages the data flow between the Client and the Server.
 */
class Connection
{
public:
	Connection( std::unique_ptr< network::udp::Socket > socket, std::unique_ptr< Player > player );

	/**
	 * This funtion exchanges ClientData and ServerData between Client and Player.
	 */
	void exchangeData();
	void disconnect();
private:
	std::unique_ptr< Player > mPlayer;
};
