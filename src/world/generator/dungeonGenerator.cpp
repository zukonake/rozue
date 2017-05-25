#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <ctime>
//
#include <world/tile/tileSubtype.hpp>
#include <world/tile/tile.hpp>
#include <world/map.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/entity/entity.hpp>
#include <world/world.hpp>
#include <objects/tileSubtypes.hpp>
#include <objects/entitySubtypes.hpp>
#include "dungeonGenerator.hpp"

#include <iostream>

DungeonGenerator::DungeonGenerator( Size2 const &minSize, Size2 const &maxSize, float const &density ) :
	mMinSize( minSize ),
	mMaxSize( maxSize ),
	mDensity( density )
{
	srand( time( nullptr ));
}

World DungeonGenerator::generate()
{
	Tile wall( &stoneWall );
	Tile floor( &stoneFloor );
	Map map( floor );
	uint64_t levelArea = global::mapSize.x * global::mapSize.y;
	std::cout << levelArea << "\n";
	uint64_t dungeonMaxArea = mMaxSize.x * mMaxSize.y;
	std::cout << dungeonMaxArea << "\n";
	uint64_t emptyArea = ( float )levelArea * mDensity;
	std::cout << emptyArea << "\n";
	uint16_t dungeonNumber = emptyArea / dungeonMaxArea;
	std::cout << dungeonNumber << "\n";
	generateDungeons( dungeonNumber );
	applyDungeons( map, wall );
	World world( map );
	world.createPlayer( human );
	return world;
}

DungeonGenerator::Dungeon DungeonGenerator::randomizeDungeon()
{
	Dungeon dungeon;
	dungeon.size = 
	{
		( rand() % ( mMaxSize.x - mMinSize.x )) + mMinSize.x,
		( rand() % ( mMaxSize.y - mMinSize.y )) + mMinSize.y
	};
	dungeon.position =
	{
		( rand() % (( global::mapSize.x - 1 ) - dungeon.size.x ) + 1 ),
		( rand() % (( global::mapSize.y - 1 ) - dungeon.size.y ) + 1 ),
		rand() % global::mapSize.z
	};
	return dungeon;
}

void DungeonGenerator::generateDungeons( uint16_t const &number )
{
	for( uint16_t iZ = 0; iZ < global::mapSize.z; iZ++ )
	{
		for( uint16_t i = 0; i < number; i++ )
		{
			Dungeon dungeon;
			do
			{
				dungeon = randomizeDungeon();
				dungeon.position.z = iZ;
			} while( !good( dungeon ));
			std::cout << "INFO: New dungeon: {"
				  	  << dungeon.position.x
				  	  << ", "
				  	  << dungeon.position.y
				  	  << ", "
				  	  << dungeon.position.z
				  	  << "}, {"
				  	  << dungeon.size.x
				  	  << ", "
				  	  << dungeon.size.y
				  	  << "}\n";
			mDungeons.push_back( dungeon );
		}
	}
}

void DungeonGenerator::applyDungeons( Map &map, Tile const &fill )
{
	for( auto iDungeon : mDungeons )
	{
		uint16_t iZ = iDungeon.position.z;
		for( uint16_t iY = iDungeon.position.y;
			 iY < iDungeon.position.y + iDungeon.size.y;
			 iY++ )
		{
			for( uint16_t iX = iDungeon.position.x;
				 iX < iDungeon.position.x + iDungeon.size.x;
				 iX++ )
			{
				map[{ iX, iY, iZ }] = fill;
			}
		}
	}
}

bool DungeonGenerator::good( Dungeon const &dungeon )
{
	for( auto iDungeon : mDungeons )
	{
		if( touches( dungeon, iDungeon ))
		{
			return false;
		}
	}
	return true;
}

bool DungeonGenerator::touches( Dungeon const &one, Dungeon const &two )
{
	Dungeon oneBorder = one;
	oneBorder.position.x--;
	oneBorder.position.y--;
	oneBorder.size.x += 2;
	oneBorder.size.y += 2;

	Dungeon twoBorder = two;
	twoBorder.position.x--;
	twoBorder.position.y--;
	twoBorder.size.x += 2;
	twoBorder.size.y += 2;

	return intersects( oneBorder, twoBorder );
}

bool DungeonGenerator::intersects( Dungeon const &one, Dungeon const &two )
{
	if( one.position.z != two.position.z )
	{
		return false;
	}
	return ( one.position.x < two.position.x + two.size.x &&
			 one.position.y < two.position.y + two.size.y &&
			 one.position.x + one.size.x > two.position.x &&
			 one.position.y + one.size.y > two.position.y );
}
