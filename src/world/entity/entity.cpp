#include <world/typedef.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/world.hpp>
#include "entity.hpp"

namespace coldline
{

Entity::Entity( World &world, WorldPoint const &position, EntitySubtype const &subtype ) noexcept :
	mWorld( world ),
	mSubtype( subtype ),
	mPosition( position )
{

}

bool Entity::move( WorldVector const &by )
{
	WorldPoint newPosition = mPosition + by;
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

bool Entity::teleport( WorldPoint const &to )
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

WorldPoint const &Entity::getPosition() const noexcept
{
	return mPosition;
}

bool Entity::passable() const noexcept
{
	return !mSubtype.mSolid;
}

bool Entity::canMove( WorldPoint const &to )
{
	return mWorld.canMove( mPosition, to );
}

}
