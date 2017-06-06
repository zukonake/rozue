#include <cstdlib>
#include <cstdlib>
#include <ctime>
//
#include <data/dataset.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/chunk/chunk.hpp>
#include "wallGenerator.hpp"

namespace coldline
{

WallGenerator::WallGenerator( Dataset const &dataset ) :
	mDataset( dataset )
{
	srand( time( NULL ));
}

Chunk WallGenerator::generate( chunk::Point const &position )
{
	( void )position;
	Chunk chunk;
	for( unsigned iZ = 0; iZ < Chunk::size.z; iZ++ )
	{
		for( unsigned iY = 0; iY < Chunk::size.y; iY++ )
		{
			for( unsigned iX = 0; iX < Chunk::size.x; iX++ )
			{
				if( rand() % 10 == 0 )
				{
					chunk[{ iX, iY, iZ }] = mDataset.at< TileSubtype >( "stoneWall" );
				}
				else
				{
					chunk[{ iX, iY, iZ }] = mDataset.at< TileSubtype >( "stoneFloor" );
				}
			}
		}
	}
	return chunk;
}

}
