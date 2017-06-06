#include <cstdint>
#include <cmath>
//
#include <world/typedef.hpp>
#include <render/typedef.hpp>
#include <render/tile.hpp>
#include <render/tileMap.hpp>
#include <render/sprite.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/world.hpp>
#include <world/entity/entity.hpp>
#include "camera.hpp"

namespace coldline
{

Camera::Camera(
	render::Tile const &nothing,
	World &world,
	Entity &entity,
	render::Size screenSize,
	render::Size spriteSize ) :
		mLocked( true ),
		mScale({ 1.f, 1.f }),
		mScreenSize( screenSize ),
		mSpriteSize( spriteSize ),
		mNothing( nothing ),
		mWorld( world ),
		mEntity( &entity ),
		mPosition( mEntity->getPosition())
{
	lock();
}

bool Camera::move( world::Vector3 const &by )
{
	if( mLocked )
	{
		if( mEntity->move( by ))
		{
			mPosition += by;
			return true;
		}
	}
	else
	{
		mPosition += by;
	}
	return false;
}

bool Camera::teleport( world::Point3 const &to )
{
	if( mLocked )
	{
		if( mEntity->teleport( to ))
		{
			mPosition = to;
			return true;
		}
	}
	else
	{
		mPosition = to;
	}
	return false;
}

void Camera::lock()
{
	teleport( mEntity->getPosition());
	mLocked = true;
}

void Camera::unlock()
{
	mLocked = false;
}

void Camera::setScale( render::Scale const &scale )
{
	mScale = scale;
}

void Camera::changeScale( render::Scale const &scale )
{
	if( scale.x > -mScale.x && scale.y > -mScale.y )
	{
		mScale += scale;
	}
}

std::queue< Sprite > Camera::getRenderQueue()
{
	std::queue< Sprite > renderQueue; //TODO maybe change to vector? TODO typedef?
	world::Point3 worldPosition;
	render::Point spritePosition;
	worldPosition.z = mPosition.z;
	for( worldPosition.y = mPosition.y - mFov, spritePosition.y = 0;
		worldPosition.y < mPosition.y + mFov;
		worldPosition.y++, spritePosition.x = 0, spritePosition.y += mSpriteSize.y * mScale.y )
	{
		for( worldPosition.x = mPosition.x - mFov;
			worldPosition.x < mPosition.x + mFov;
			worldPosition.x++, spritePosition.x += mSpriteSize.x * mScale.x )
		{
			render::Surface surface( spritePosition, { mSpriteSize * mScale });
			if( !sees( worldPosition ))
			{
				renderQueue.emplace(
				surface,
					mNothing );
			}
			else
			{
				renderQueue.emplace(
					surface,
					mWorld[ worldPosition ].getRenderTile());
				if( mWorld.entityOn( worldPosition ))
				{
					renderQueue.emplace(
						surface,
						mWorld.getEntityOn( worldPosition ).getRenderTile());
				}
			}
		}
	}
	return renderQueue;
}

//TODO candidate for deletion
bool Camera::sees( world::Point3 const &what ) const
{
	return mWorld.sees( mEntity->getPosition(), what );
}

}
