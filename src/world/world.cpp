#include <world/tile/tileSubtype.hpp>
#include <world/tile/tile.hpp>
#include <world/entity/entity.hpp>
#include <world/generator/generator.hpp>
#include "world.hpp"

namespace coldline
{

World::World( Generator * const &generator ) :
	mGenerator( generator ),
	mMap( *generator )
{

}



World::~World()
{
	delete mGenerator;
}



Tile &World::operator[]( map::Point3 const &point )
{
	return mMap[ point ];
}



bool World::sees( map::Point3 const &from, map::Point3 const &to )
{
	if( !exists( to ) || !exists( from ))
	{
		return false;
	}
	auto plot = map::Line3( from, to ).getPlot();
	if( plot.empty())
	{
		return false;
	}
	for( unsigned i = 1; i < plot.size() - 1; i++ )
	{
		if( operator[]( plot[ i ]).passable())
		{
			return false;
		}
		if( entityOn( plot[ i ]))
		{
			if( getEntityOn( plot[ i ]).passable())
			{
				return false;
			}
		}
	}
	return true;
}

bool World::canMove( map::Point3 const &from, map::Point3 const &to )
{
	return sees( from, to ) && operator[]( to ).passable() && !entityOn( to );
}

bool World::entityOn( map::Point3 const &point ) const
{
	return mEntitiesMap.count( point );
}



Entity const &World::getEntityOn( map::Point3 const &point ) const
{
	return *mEntitiesMap.at( point );
}

Entity &World::createEntity( map::Point3 const &position, EntitySubtype const &subtype )
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
	return createEntity( { 0, 0, 0 }, subtype ); //TODO
}



void World::moveEntity( map::Point3 const &from, map::Point3 const &to )
{
	mEntitiesMap[ to ] = mEntitiesMap[ from ];
	mEntitiesMap.erase( from );
}

void World::simulate()
{

}

bool World::exists( map::Point3 const &point )
{
	return mMap.exists( point );
}

}
