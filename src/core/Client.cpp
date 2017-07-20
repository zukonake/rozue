#include <string>
//
#include <utility/Logger.hpp>
#include <core/common.hpp>
#include <network/common.hpp>
#include <network/UDPSocket.hpp>
#include <data/ClientData.hpp>
#include <data/ServerData.hpp>
#include "Client.hpp"

Client::Client( ID const &ID ) :
	mID( ID )
{
	utility::logger.log( "C", utility::Logger::DEBUG, "creating client with ID: " + ID );
}

/*ClientData Client::requestClientData()
{
	//TODO
}*/

/*void Client::receiveServerData( ServerData const &serverData )
{
	//TODO
}*/

void Client::connectTo( network::IP const &IPAddress, network::Port const &port )
{
	//TODO timeout as a arg?
	utility::logger.log( "C", utility::Logger::ERROR,
		"could not connect to " + IPAddress + ":" + std::to_string( port ));
}

void Client::disconnect()
{
}

bool Client::isConnected() const noexcept
{
	return false; //TODO
}

ID const &Client::getID() const noexcept
{
	return mID;
}

/*void Client::parseServerData( ServerData const &serverData )
{
	//TODO
}*/
