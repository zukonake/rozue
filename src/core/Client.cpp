#include <string>
//
#include <utility/Logger.hpp>
#include <data/ClientData.hpp>
#include <data/ServerData.hpp>
#include "Client.hpp"

Client::Client( Nickname const &nickname ) :
	mNickname( nickname )
{

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
