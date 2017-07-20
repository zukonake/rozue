#include <utility>
//
#include <data/ServerData.hpp>
#include "Connection.hpp"

void Connection::exchangeData()
{
	mPlayer->requestServerData();
}

void Connection::disconnect()
{
	//TODO
}
