#include <world/map/typedef.hpp>
#include "entityMap.hpp"

namespace coldline
{

void EntityMap::simulate()
{

}

void EntityMap::moveEntity( map::Point3 const &from, map::Point3 const &to )
{
	mEntitiesMap[ to ] = mEntitiesMap[ from ];
	mEntitiesMap.erase( from );
}

Entity &EntityMap::createEntity( world::Position const &position, EntitySubtype const &subtype )
{
	if( !entityOn( position.point ))
	{
		mEntities.emplace_back( mWorld, position, subtype );
		mEntitiesMap.emplace( position, &mEntities.back());
	}
	return *mEntitiesMap.at( position.point );
}

bool EntityMap::entityOn( map::Point3 const &point ) const
{
	return mEntitiesMap.count( point );
}

bool EntityMap::canMove( map::Point3 const &to ) const
{
	return !entityOn( to );
}

Entity const &EntityMap::getEntityOn( map::Point3 const &point ) const
{
	return *mEntitiesMap.at( point );
}

}
