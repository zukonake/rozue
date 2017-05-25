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
	map[{ 5, 5, 0 }] = wall;
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
		rand() % ( global::mapSize.x - dungeon.size.x ),
		rand() % ( global::mapSize.y - dungeon.size.y ),
		0//rand() % global::mapSize.z
	};
	return dungeon;
}

void DungeonGenerator::generateDungeons( uint16_t const &number )
{
	for( uint16_t i = 0; i < number; i++ )
	{
		Dungeon dungeon;
		do
		{
			dungeon = randomizeDungeon();
			std::cout << "New dungeon: "
					  << dungeon.position.x
					  << ", "
					  << dungeon.position.y
					  << ", "
					  << dungeon.position.z
					  << ": "
					  << dungeon.size.x
					  << ", "
					  << dungeon.size.y
					  << "\n";
		} while( !good( dungeon ));
		mDungeons.push_back( dungeon );
	}
}

void DungeonGenerator::applyDungeons( Map &map, Tile const &fill )
{
	for( auto iDungeon : mDungeons )
	{
		std::cout << "Placing dungeon...\n";
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
		if( intersects( dungeon, iDungeon ))
		{
			return false;
		}
	}
	return true;
}

bool DungeonGenerator::intersects( Dungeon const &one, Dungeon const &two )
{
	uint16_t deltaX = std::abs(( int16_t )one.position.x - ( int16_t )two.position.x );
	uint16_t deltaY = std::abs(( int16_t )one.position.y - ( int16_t )two.position.y );
	return deltaX * 2 < ( one.size.x + one.size.y ) &&
		   deltaY * 2 < ( one.size.y + one.size.y );
}
