#pragma once

#include <functional>
//
#include <core/typedef.hpp>
#include <core/player.hpp>

class Client;

class Connection
{
public:
	Connection( Client &client );

	void exchange();
private:
	Client &mClient;
	Player mPlayer;
};
