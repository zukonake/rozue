#include <cstdint>
#include <stdexcept>
#include <vector>
//
#include <global.hpp>
#include <geometry/bresenham.hpp>
#include <world/tile/tile.hpp>
#include <world/map.hpp>
#include <world/entity/entity.hpp>
#include "world.hpp"

World::World( Map const &map ) :
	mMap( map )
{

}

Tile &World::operator[]( Point3 const &index )
{
	return mMap[ index ];
}

Tile const &World::operator[]( Point3 const &index ) const
{
	return mMap[ index ];
}

Point3 World::getStartPosition() const
{
	Point3 returnValue;
	returnValue.z = 0;
	do
	{
		returnValue.x = rand() % global::mapSize.x;
		returnValue.y = rand() % global::mapSize.y;
	} while( !mMap[ returnValue ].passable() ||
		entityOn( returnValue ));
	return returnValue;
}

Point3 World::getFreePosition() const
{
	Point3 returnValue;
	do
	{
		returnValue.x = rand() % global::mapSize.x;
		returnValue.y = rand() % global::mapSize.y;
		returnValue.z = rand() % global::mapSize.z;
	} while( !mMap[ returnValue ].passable() ||
		entityOn( returnValue ));
	return returnValue;
}

Entity &World::getEntityOn( Point3 const &point )
{
	return *mEntitiesMap.at( point );
}

Entity const &World::getEntityOn( Point3 const &point ) const
{
	return *mEntitiesMap.at( point );
}

bool World::entityOn( Point3 const &point ) const
{
	return mEntitiesMap.count( point );
}

bool World::sees( Point3 const &from, Point3 const &to ) const
{
	if( !exists( to ) || !exists( from ))
	{
		return false;
	}
	std::vector< Point3 > line = bresenham::plotLine( from, to );
	if( line.empty())
	{
		return false;
	}
	for( uint16_t i = 1; i < line.size() - 1; i++ )
	{
		if( !mMap[ line[ i ]].passable())
		{
			return false;
		}
		if( entityOn( line[ i ]))
		{
			if( getEntityOn( line[ i ]).passable())
			{
				return false;
			}
		}
	}
	return true;
}

void World::simulate()
{

}

bool World::moveEntity( Point3 const &from, Point3 const &to )
{
	if( !entityOn( to ))
	{
		mEntitiesMap[ to ] = mEntitiesMap[ from ];
		mEntitiesMap.erase( from );
		return true;
	}
	else
	{
		return false;
	}
}

Entity &World::createEntity( EntitySubtype const &subtype, Point3 const &position )
{
	if( !entityOn( position ))
	{
		mEntities.emplace_back( *this, position, subtype );
		mEntitiesMap.emplace( position, &mEntities.back());
	}
	return *mEntitiesMap.at( position );
}

Entity &World::createPlayer( EntitySubtype const &subtype )
{
	return createEntity( subtype, getStartPosition());
}

bool World::exists( Point3 const &where )
{
	return where.x < global::mapSize.x &&
		   where.y < global::mapSize.y &&
		   where.z < global::mapSize.z;
}
