#include <cstdlib>
#include <ctime>
//
#include <world/tile/tileSubtype.hpp>
#include <world/tile/tile.hpp>
#include <world/map.hpp>
#include <data/dataset.hpp>
#include <world/world.hpp>
#include "randomWallsGenerator.hpp"

RandomWallsGenerator::RandomWallsGenerator( Dataset const &dataset, float const &density ) :
	mDataset( dataset ),
	mDensity( density )
{
	srand( time( nullptr ));
}

World RandomWallsGenerator::generate()
{
	Tile fill( &mDataset.at< TileSubtype >( "stoneFloor" ));
	Map map( fill );
	for( uint16_t iZ = 0; iZ < global::mapSize.z; iZ++ )
	{
		for( uint16_t iY = 0; iY < global::mapSize.y; iY++ )
		{
			for( uint16_t iX = 0; iX < global::mapSize.x; iX++ )
			{
				if(( rand() % ( int )( 1.f / mDensity )) == 0 )
				{
					map[{ iX, iY, iZ }] = mDataset.at< TileSubtype >( "stoneWall" );
				}
			}
		}
	}
	World world( map );
	return world;
}
