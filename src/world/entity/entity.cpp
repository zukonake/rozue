#include <world/typedef.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/world.hpp>
#include "entity.hpp"

namespace coldline
{

Entity::Entity( World &world, WorldPoint3 const &position, EntitySubtype const &subtype ) noexcept :
	mWorld( world ),
	mSubtype( subtype ),
	mPosition( position )
{

}

bool Entity::move( WorldVector3 const &by )
{
	WorldPoint3 newPosition = mPosition + by;
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

bool Entity::teleport( WorldPoint3 const &to )
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

RenderTile const &Entity::getRenderTile() const noexcept
{
	return mSubtype.mRenderTile;
}

WorldPoint3 const &Entity::getPosition() const noexcept
{
	return mPosition;
}

bool Entity::passable() const noexcept
{
	return !mSubtype.mSolid;
}

bool Entity::canMove( WorldPoint3 const &to )
{
	return mWorld.canMove( mPosition, to );
}

}
