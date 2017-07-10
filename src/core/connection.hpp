#pragma once

#include <functional>
//
#include <core/typedef.hpp>
#include <core/player.hpp>

class Client;

/**
 * Connection manages the data flow between the Client and the Server.
 */
class Connection
{
public:
	Connection( Client &client );

	/**
	 * This funtion exchanges ClientData and ServerData between Client and Player.
	 */
	void exchangeData();
	void disconnect();
private:
	Client &mClient;
	Player mPlayer;
};
