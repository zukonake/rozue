#include <cstdint>
#include <cmath>
//
#include <render/typedef.hpp>
#include <render/tile.hpp>
#include <render/sprite.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/world.hpp>
#include <world/entity/entity.hpp>
#include "camera.hpp"

namespace coldline
{

Camera::Camera( render::Tile const &nothing, World &world, Entity &entity ) :
	mLocked( true ),
	mScale({ 1.f, 1.f }),
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

std::queue< Sprite > Camera::getRenderQueue() const
{
	std::queue< Sprite > renderQueue;
	//TODO
	return renderQueue;
}

//TODO candidate for deletion
bool Camera::sees( world::Point3 const &what ) const
{
	return mWorld.sees( mEntity->getPosition(), what );
}

}
