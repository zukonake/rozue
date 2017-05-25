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
	Map map( wall );
	uint64_t levelArea = global::mapSize.x * global::mapSize.y;
	std::cout << levelArea << "\n";
	uint64_t dungeonMaxArea = mMaxSize.x * mMaxSize.y;
	std::cout << dungeonMaxArea << "\n";
	uint64_t emptyArea = ( float )levelArea * mDensity;
	std::cout << emptyArea << "\n";
	uint16_t dungeonNumber = emptyArea / dungeonMaxArea;
	std::cout << dungeonNumber << "\n";
	generateDungeons( dungeonNumber );
	applyDungeons( map, floor );
	generateCorridors();
	applyCorridors( map, floor );
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
		( rand() % (( global::mapSize.y - 1 ) - dungeon.size.y ) + 1 )
	};
	return dungeon;
}

void DungeonGenerator::generateDungeons( uint16_t const &number )
{
	uint32_t const maxTries = 50;
	for( uint16_t iZ = 0; iZ < global::mapSize.z; iZ++ )
	{
		for( uint16_t i = 0; i < number; i++ )
		{
			Dungeon dungeon;
			uint32_t tries = 0;
			do
			{
				dungeon = randomizeDungeon();
				tries++;
			} while( !good( dungeon, iZ && tries < maxTries ));
			if( tries < maxTries )
			{
				std::cout << "INFO: New dungeon: {"
				  	  	  << dungeon.position.x
				  	  	  << ", "
				  	  	  << dungeon.position.y
				  	  	  << "}, {"
				  	  	  << dungeon.size.x
				  	  	  << ", "
				  	  	  << dungeon.size.y
				  	  	  << "}\n";
				mDungeons[ iZ ].push_back( dungeon );
			}
		}
	}
}

void DungeonGenerator::applyDungeons( Map &map, Tile const &fill )
{
	for( uint16_t iZ = 0; iZ < global::mapSize.z; iZ++ )
	{
		for( auto &iDungeon : mDungeons[ iZ ] )
		{
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
}

void DungeonGenerator::generateCorridors()
{
	uint32_t const maxTries = 500;
	float const corridorDensity = 0.125f;
	for( uint16_t iZ = 0; iZ < global::mapSize.z; iZ++ )
	{
		for( auto &from : mDungeons[ iZ ] )
		{
			uint8_t corridorNumber = ( rand() % 2 ) + 1;
			for( uint8_t i = 0; i < corridorNumber; i++ )
			{
				Point2 fromOrigin = getOrigin( from );
				Point2 toOrigin;
				uint32_t tries = 0;
				do
				{
					Dungeon to;
					to = mDungeons[ iZ ][ rand() % mDungeons[ iZ ].size()];
					tries++;
					toOrigin = getOrigin( to );
				} while(( getDistance( fromOrigin, toOrigin ) >= ( tries * corridorDensity ) + 1 &&
						 tries < maxTries )||
						 toOrigin == fromOrigin );
				if( tries < maxTries )
				{
					std::cout << "INFO: New corridor: {"
					  	  	  << fromOrigin.x
					  	  	  << ", "
					  	  	  << fromOrigin.y
					  	  	  << "}, {"
					  	  	  << toOrigin.x
					  	  	  << ", "
					  	  	  << toOrigin.y
					  	  	  << "}\n";
					mCorridors[ iZ ].push_back({ fromOrigin, toOrigin });
				}
			}
		}
	}
}

void DungeonGenerator::applyCorridors( Map &map, Tile const &fill )
{
	for( uint16_t iZ = 0; iZ < global::mapSize.z; iZ++ )
	{
		for( auto &iCorridor : mCorridors[ iZ ] )
		{
			if( iCorridor.from.y < iCorridor.to.y )
			{
				for( uint16_t iY = iCorridor.from.y; iY <= iCorridor.to.y; iY++ )
				{
					map[{ iCorridor.from.x, iY, iZ }] = fill;
				}
			}
			else
			{
				for( uint16_t iY = iCorridor.from.y; iY >= iCorridor.to.y; iY-- )
				{
					map[{ iCorridor.from.x, iY, iZ }] = fill;
				}
			}
			if( iCorridor.from.x < iCorridor.to.x )
			{
				for( uint16_t iX = iCorridor.from.x; iX <= iCorridor.to.x; iX++ )
				{
					map[{ iX, iCorridor.to.y, iZ }] = fill;
				}
			}
			else
			{
				for( uint16_t iX = iCorridor.from.x; iX >= iCorridor.to.x; iX-- )
				{
					map[{ iX, iCorridor.to.y, iZ }] = fill;
				}
			}
		}
	}
}

bool DungeonGenerator::good( Dungeon const &dungeon, uint16_t level )
{
	for( auto &iDungeon : mDungeons[ level ] )
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
	return ( one.position.x < two.position.x + two.size.x &&
			 one.position.y < two.position.y + two.size.y &&
			 one.position.x + one.size.x > two.position.x &&
			 one.position.y + one.size.y > two.position.y );
}

uint16_t DungeonGenerator::getDistance( Point2 const &from, Point2 const &to )
{
	uint16_t deltaX = std::abs(( int16_t )from.x - ( int16_t )to.x );
	uint16_t deltaY = std::abs(( int16_t )from.y - ( int16_t )to.y );
	return std::sqrt( std::pow( deltaX, 2 ) + std::pow( deltaY, 2 ));
}

Point2 DungeonGenerator::getOrigin( Dungeon const &dungeon )
{
	return
	{
		dungeon.position.x + ( dungeon.size.x / 2 ),
		dungeon.position.y + ( dungeon.size.y / 2 )
	};
}
