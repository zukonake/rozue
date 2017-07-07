#pragma once

#include <core/typedef.hpp>

class Server;

class Client
{
public:
	Client( ClientID const &clientID );
private:
	ClientID mID;
	Server *mServer;
};
