#include <string>
//
#include <utility/Logger.hpp>
#include <data/ClientData.hpp>
#include <data/ServerData.hpp>
#include "Client.hpp"

Client::Client( Nickname const &nickname ) :
	mNickname( nickname )
{
	utility::logger.log( "C", utility::Logger::INFO, "creating client: " + nickname );
}

void Client::connectTo( network::IP address, network::Port port )
{
	utility::logger.log( "C", utility::Logger::INFO, "connecting to: " + address + ":" + std::to_string( port ));
	network::cold::Socket::connectTo( address, port );
}

void Client::send()
{

}

ServerData Client::receive()
{
	return ServerData();
}

Nickname Client::getNickname()
{
	return mNickname;
}
