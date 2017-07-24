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

/*ClientData Client::requestClientData()
{
	//TODO
}*/

/*void Client::receiveServerData( ServerData const &serverData )
{
	//TODO
}*/

/*void Client::parseServerData( ServerData const &serverData )
{
	//TODO
}*/
