#pragma once

struct ServerData;
struct ClientData;

class Player
{
public:
	ServerData requestServerData();
	void receiveClientData( ClientData const &clientData );
private:
};
