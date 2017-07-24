#include <string>
//
#include <utility/Logger.hpp>
#include <network/common.hpp>
#include <network/UDPSocket.hpp>
#include <data/ClientData.hpp>
#include <data/ServerData.hpp>
#include "Client.hpp"

Client::Client( Nickname const &nickname ) :
	mNickname( nickname )
{

}

void Client::send( network::Data const &datagram )
{
	(void)datagram;
}

network::Data Client::receive()
{
	return network::Data();
}

Nickname Client::getNickname()
{
	return mNickname;
}
