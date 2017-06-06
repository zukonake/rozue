#include <data/dataset.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/chunk/chunk.hpp>
#include "flatGenerator.hpp"

namespace coldline
{

FlatGenerator::FlatGenerator( Dataset const &dataset ) :
	mDataset( dataset )
{

}

Chunk FlatGenerator::generate( chunk::Point const &position )
{
	( void )position;
	Chunk chunk;
	for( unsigned iZ = 0; iZ < Chunk::size.z; iZ++ )
	{
		for( unsigned iY = 0; iY < Chunk::size.y; iY++ )
		{
			for( unsigned iX = 0; iX < Chunk::size.x; iX++ )
			{
				chunk[{ iX, iY, iZ }] = mDataset.at< TileSubtype >( "stoneFloor" );
			}
		}
	}
	return chunk;
}

}
