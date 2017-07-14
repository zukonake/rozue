#include <utility>
//
#include <data/serverData.hpp>
#include "connection.hpp"

Connection::Connection( std::unique_ptr< Network::TCPSocket > socket, std::unique_ptr< Player > player ) :
	mSocket( std::move( socket )),
	mPlayer( std::move( player ))
{

}

void Connection::exchangeData()
{
	mPlayer->requestServerData();
}

void Connection::disconnect()
{
	//TODO
}
