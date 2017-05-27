#include <cstdint>
#include <cmath>
//
#include <geometry/scale.hpp>
#include <render/renderable.hpp>
#include <render/transformedSprite.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/world.hpp>
#include "camera.hpp"

Camera::Camera( Entity const &entity, World const &world, Sprite const &nothing ) :
	Entity( entity ),
	mWorld( world ),
	mNothing( nothing ),
	mPosition( Entity::getPosition()),
	mLocked( true ),
	mScale({ 1.f, 1.f })
{
	lock();
}

bool Camera::move( Vector const &by )
{
	if( mLocked )
	{
		if( Entity::move( by ))
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

bool Camera::teleport( Point3 const &to )
{
	if( mLocked )
	{
		if( Entity::teleport( to ))
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
	teleport( Entity::getPosition());
	mLocked = true;
}

void Camera::unlock()
{
	mLocked = false;
}

void Camera::setScale( Scale2 const &scale )
{
	mScale = scale;
}

void Camera::changeScale( Scale2 const &scale )
{
	if( scale.x > -mScale.x && scale.y > -mScale.y )
	{
		mScale += scale;
	}
}

std::queue< TransformedSprite > Camera::getSprites() const
{
	std::queue< TransformedSprite > sprites;
	coldline::geometry::Vector3i iRelative = { 0, 0, ( int16_t )mPosition.z };
	coldline::geometry::Vector2f iScreen;
	for( iRelative.y = mPosition.y - ( mFov / mScale.y ), iScreen.y = 0;
		 iRelative.y <= ( int16_t )mPosition.y + ( mFov / mScale.y );
		 iRelative.y++, iScreen.y += global::screenSpriteSize.y * mScale.y )
	{
		for( iRelative.x = mPosition.x - ( mFov / mScale.x ), iScreen.x = 0;
			 iRelative.x <= ( int16_t )mPosition.x + ( mFov / mScale.x );
			 iRelative.x++, iScreen.x += global::screenSpriteSize.x * mScale.x )
		{
			Scale2 scale = mScale * global::spriteScale;
			if( iRelative.x < 0 || iRelative.y < 0 || iRelative.z < 0 ||
				!sees( iRelative ))
			{
				addSprite( sprites, mNothing, iScreen, scale );
			}
			else
			{
				Point3 iMap = iRelative;
				addSprite( sprites,
					mWorld[ iMap ],
					( Point2 )iScreen,
					scale );
				if( mWorld.entityOn( iMap ))
				{
					addSprite( sprites, mWorld.getEntityOn( iMap ), iScreen, scale );
				}
			}
		}
	}
	return sprites;
}

void Camera::addSprite( std::queue< TransformedSprite > &sprites,
	Renderable const &sprite,
	Point2 const &position,
	Scale2 const &scale )
{
	sprites.emplace( sprite );
	sprites.back().setPosition( position );
	sprites.back().scale( scale );
}

//TODO candidate for deletion
bool Camera::sees( Point3 const &what ) const
{
	return mWorld.sees( Entity::getPosition(), what );
}
