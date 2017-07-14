#include <string>
//
#include <utility/logger.hpp>
#include <core/exception.hpp>
#include <core/network.hpp>
#include <data/clientData.hpp>
#include <data/serverData.hpp>
#include "client.hpp"

Client::Client( Network::ID const &ID ) :
	mID( ID )
{
	globalLogger.log( "C", Logger::DEBUG, "creating client with ID: " + ID );
}

/*ClientData Client::requestClientData()
{
	//TODO
}*/

/*void Client::receiveServerData( ServerData const &serverData )
{
	//TODO
}*/

void Client::connectTo( Network::IP const &IPAddress, Network::Port const &port )
{
	//TODO timeout as a arg?
	globalLogger.log( "C", Logger::INFO,
		"connecting to " + IPAddress.toString() + ":" + std::to_string( port ));
	if( mSocket.connect( IPAddress, port, sf::seconds( 1 )) != Network::Socket::Done )
	{
		globalLogger.log( "C", Logger::ERROR,
			"could not connect to " + IPAddress.toString() + ":" + std::to_string( port ));
		throw Exception::CouldNotConnect(
			"Client::connectTo: could not connect to: " +
			IPAddress.toString() + ":" + std::to_string( port ));
	}
}

void Client::disconnect()
{
	if( !isConnected())
	{
		throw Exception::NotConnected( "Client::disconnect: client is not connected" );
	}
	globalLogger.log( "C", Logger::DEBUG, "disconnecting from: " +
		mSocket.getRemoteAddress().toString() + ":" +
		std::to_string( mSocket.getRemotePort()));
	mSocket.disconnect();
}

bool Client::isConnected() const noexcept
{
	return mSocket.getRemoteAddress() != Network::IP::None;
}

Network::ID const &Client::getID() const noexcept
{
	return mID;
}

/*void Client::parseServerData( ServerData const &serverData )
{
	//TODO
}*/
