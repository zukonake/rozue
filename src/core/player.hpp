#pragma once

class ServerData;
class ClientData;

/**
 * Player is the server-side representation of Client.
 *
 * Player prepares ServerData and receives ClientData.
 * In other words, it is the interface for Client to
 * interact with the Server. With that system Client
 * has no direct access to the Server, which prevents
 * cheating.
 */
class Player
{
public:
	ServerData requestServerData();
	void receiveClientData( ClientData const &clientData );
private:
};
