#pragma once

struct ServerData;
struct ClientData;
class Dataset;
class World;

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
	Player( Dataset const &dataset, World &world );
	ServerData requestServerData();
	void receiveClientData( ClientData const &clientData );
private:
	Dataset const &mDataset;
	World &mWorld;
};
