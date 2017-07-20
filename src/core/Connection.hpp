#pragma once

#include <memory>
//
#include <network/ColdSocket.hpp>
#include <core/Player.hpp>

class Client;

/**
 * Connection manages the data flow between the Client and the Server.
 */
class Connection
{
public:
	Connection( network::ColdSocket const &socket, std::unique_ptr< Player > player );

	/**
	 * This funtion exchanges ClientData and ServerData between Client and Player.
	 */
	void exchangeData();
	void disconnect();
private:
	std::unique_ptr< Player > mPlayer;
};
