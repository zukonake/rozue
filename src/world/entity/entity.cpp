#include <global.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/world.hpp>
#include "entity.hpp"

Entity::Entity( World &world, Point3 const &position, EntitySubtype const &subtype ) :
	mWorld( world ),
	mSubtype( subtype ),
	mPosition( position )
{

}

Sprite const &Entity::getSprite() const
{
	return mSubtype;
}

bool Entity::move( Vector const &by )
{
	Point3 newPosition = mPosition + by;
	if( World::exists( newPosition )) 
	{
		if( mWorld[ newPosition ].passable())
		{
			mPosition = newPosition; //TODO check with pathfind
			return true;
		}
	}
	return false;
}

bool Entity::teleport( Vector const &to )
{
	if( World::exists( to )) 
	{
		if( mWorld[ to ].passable())
		{
			mPosition = to; //TODO check with pathfind
			return true;
		}
	}
	return false;
}

Point3 const &Entity::getPosition() const noexcept
{
	return mPosition;
}
