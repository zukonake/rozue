#include <data/ServerData.hpp>
#include "Player.hpp"

Player::Player( Dataset const &dataset, World &world ) :
	mDataset( dataset ),
	mWorld( world )
{

}

ServerData Player::requestServerData()
{
	ServerData serverData;
	return serverData;
}
