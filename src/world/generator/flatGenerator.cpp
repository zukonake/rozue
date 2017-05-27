#include <vector>
//
#include <world/tile/tileSubtype.hpp>
#include <world/tile/tile.hpp>
#include <world/map.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/entity/entity.hpp>
#include <data/dataset.hpp>
#include <world/world.hpp>
#include "flatGenerator.hpp"

FlatGenerator::FlatGenerator( Dataset const &dataset ) :
	mDataset( dataset )
{

}

World FlatGenerator::generate()
{
	Tile fill( &mDataset.at< TileSubtype >( "stoneFloor" ));
	Map map( fill );
	std::vector< Entity > entities;
	World world( map, entities );
	world.createPlayer( mDataset.at< EntitySubtype >( "human" ));
	return world;
}
