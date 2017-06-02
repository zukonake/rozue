#include <SFML/Graphics/RenderTarget.hpp>
//
#include <world/map/typedef.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/map/map.hpp>
#include <world/world.hpp>
#include "entity.hpp"

namespace coldline
{

Entity::Entity( World &world, map::Point3 const &position, EntitySubtype const &subtype ) :
	mWorld( world ),
	mSubtype( subtype ),
	mPosition( position )
{

}

void Entity::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	target.draw( mSubtype, states );
}

bool Entity::move( map::Vector3 const &by )
{
	map::Point3 newPosition = mPosition + ( map::Point3 )by;
	if( canMove( newPosition ))
	{
		mWorld.moveEntity( mPosition, newPosition );
		mPosition = newPosition; //TODO check with pathfind
		return true;
	}
	else
	{
		return false;
	}
}

bool Entity::teleport( map::Point3 const &to )
{
	if( canMove( to ))
	{
		mWorld.moveEntity( mPosition, to );
		mPosition = to;
		return true;
	}
	else
	{
		return false;
	}
}

map::Point3 const &Entity::getPosition() const noexcept
{
	return mPosition;
}

bool Entity::passable() const noexcept
{
	return !mSubtype.mSolid;
}

bool Entity::canMove( map::Point3 const &to )
{
	return mWorld.canMove( mPosition, to );
}

}
