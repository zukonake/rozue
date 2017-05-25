#include <cstdint>
#include <cmath>
//
#include <world/tile/tileSubtype.hpp>
#include <world/world.hpp>
#include "camera.hpp"

Camera::Camera( World &world ) :
	Entity( world.getPlayer()),
	mWorld( world ),
	mPosition( Entity::getPosition()),
	mScale( 1.0f )
{
	lock();
}

void Camera::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	coldline::geometry::Vector3i iRelative = { 0, 0, ( int16_t )mPosition.z };
	coldline::geometry::Vector2f iScreen;
	for( iRelative.y = mPosition.y - mFov / mScale, iScreen.y = 0;
		 iRelative.y <= ( int16_t )mPosition.y + mFov / mScale;
		 iRelative.y++, iScreen.y += global::screenSpriteSize.y * mScale )
	{
		for( iRelative.x = mPosition.x - mFov / mScale, iScreen.x = 0;
			 iRelative.x <= ( int16_t )mPosition.x + mFov / mScale;
			 iRelative.x++, iScreen.x += global::screenSpriteSize.x * mScale )
		{
			sf::Transform newTransform;
			newTransform.translate({ iScreen.x, iScreen.y });
			newTransform.scale({ mScale, mScale });
			newTransform.scale( global::spriteScale );
			states.transform = newTransform;
			if( iRelative.x < 0 || iRelative.y < 0 ||
				!sees({ ( uint16_t )iRelative.x,
						( uint16_t )iRelative.y,
						( uint16_t )mPosition.z }))
			{
				continue;
			}
			Point iMap =
			{
				( uint16_t )iRelative.x,
				( uint16_t )iRelative.y,
				( uint16_t )iRelative.z
			};
			target.draw( mWorld[ Point( iMap.x, iMap.y, iMap.z ) ], states );
			if( iMap.x == Entity::getPosition().x &&
				iMap.y == Entity::getPosition().y )
			{
				target.draw( static_cast< Entity >( *this ), states );
			}
		}
	}
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

bool Camera::teleport( Vector const &to )
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

void Camera::setScale( float const &scale )
{
	mScale = scale;
}

void Camera::changeScale( float const &scale )
{
	if( scale > -mScale )
	{
		mScale += scale;
	}
}

//TODO candidate for deletion
bool Camera::sees( Point const &what ) const
{
	return mWorld.sees( Entity::getPosition(), what );
}
