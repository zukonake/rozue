#include <world/typedef.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/world.hpp>
#include "entity.hpp"

namespace coldline
{

Entity::Entity( World &world, world::Point3 const &position, EntitySubtype const &subtype ) noexcept :
	mWorld( world ),
	mSubtype( subtype ),
	mPosition( position )
{

}

bool Entity::move( world::Vector3 const &by )
{
	world::Point3 newPosition = mPosition + by;
	if( canMove( newPosition )) //TODO move entites to chunk as a vector
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

bool Entity::teleport( world::Point3 const &to )
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

render::Tile const &Entity::getRenderTile() const noexcept
{
	return mSubtype.mRenderTile;
}

world::Point3 const &Entity::getPosition() const noexcept
{
	return mPosition;
}

bool Entity::passable() const noexcept
{
	return !mSubtype.mSolid;
}

bool Entity::canMove( world::Point3 const &to )
{
	return mWorld.canMove( mPosition, to );
}

}
