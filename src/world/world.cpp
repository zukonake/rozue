#include <cstdint>
#include <vector>
//
#include <global.hpp>
#include <geometry/bresenham.hpp>
#include <world/tile/tile.hpp>
#include <world/map.hpp>
#include <world/entity/entity.hpp>
#include <objects/tileSubtypes.hpp>
#include <objects/entitySubtypes.hpp>
#include "world.hpp"

World::World( Map const &map, std::vector< Entity > const &entities ) :
	mMap( map ),
	mEntities( entities )
{

}

Tile &World::operator[]( Point const &index )
{
	return mMap[ index ];
}

Tile const &World::operator[]( Point const &index ) const
{
	return mMap[ index ];
}

Point World::getStartPosition() const
{
	Point returnValue;
	returnValue.z = 0;
	do
	{
		returnValue.x = rand() % global::mapSize.x;
		returnValue.y = rand() % global::mapSize.y;
	} while( !mMap[ returnValue ].passable());
	return returnValue;
}

Point World::getFreePosition() const
{
	Point returnValue;
	do
	{
		returnValue.x = rand() % global::mapSize.x;
		returnValue.y = rand() % global::mapSize.y;
		returnValue.z = rand() % global::mapSize.z;
	} while( !mMap[ returnValue ].passable());
	return returnValue;
}

Entity &World::getPlayer()
{
	return mEntities.at( 0 );
}

bool World::sees( Point const &from, Point const &to ) const
{
	if( !exists( to ) || !exists( from ))
	{
		return false;
	}
	std::vector< Point > line = bresenham::plotLine( from, to );
	if( line.empty())
	{
		return false;
	}
	for( uint16_t i = 0; i < line.size() - 1; i++ )
	{
		if( !mMap[ line[ i ]].passable())
		{
			return false;
		}
	}
	return true;
}

void World::simulate()
{

}

void World::createEntity( EntitySubtype const &subtype )
{
	mEntities.push_back( Entity( *this, getFreePosition(), subtype ));
}

void World::createPlayer( EntitySubtype const &subtype )
{
	mEntities.push_back( Entity( *this, getStartPosition(), subtype ));
}

bool World::exists( Point const &where )
{
	return where.x < global::mapSize.x &&
		   where.y < global::mapSize.y &&
		   where.z < global::mapSize.z;
}
