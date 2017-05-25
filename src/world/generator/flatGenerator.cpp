#include <vector>
//
#include <world/tile/tileSubtype.hpp>
#include <world/tile/tile.hpp>
#include <world/map.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/entity/entity.hpp>
#include <world/world.hpp>
#include <objects/tileSubtypes.hpp>
#include <objects/entitySubtypes.hpp>
#include "flatGenerator.hpp"

World FlatGenerator::generate()
{
	Tile fill( &stoneFloor );
	Map map( fill );
	std::vector< Entity > entities;
	World world( map, entities );
	world.createPlayer( human );
	return world;
}
