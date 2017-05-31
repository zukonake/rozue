#include <cstdint>
#include <cmath>
//
#include <render/typedef.hpp>
#include <render/sprite.hpp>
#include <render/transformedDrawable.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/map/map.hpp>
#include <world/world.hpp>
#include "camera.hpp"

namespace coldline
{

Camera::Camera( Sprite const &nothing, World &world, Entity &entity ) :
	mLocked( true ),
	mScale({ 1.f, 1.f }),
	mNothing( nothing ),
	mWorld( world ),
	mEntity( entity ),
	mPosition( mEntity.get().getPosition())
{
	lock();
}

bool Camera::move( map::Vector3 const &by )
{
	if( mLocked )
	{
		if( mEntity.get().move( by ))
		{
			mPosition.point += by;
			return true;
		}
	}
	else
	{
		mPosition.point += by;
	}
	return false;
}

bool Camera::teleport( map::Point3 const &to )
{
	if( mLocked )
	{
		if( mEntity.get().teleport( to ))
		{
			mPosition.point = to;
			return true;
		}
	}
	else
	{
		mPosition.point = to;
	}
	return false;
}

void Camera::lock()
{
	teleport( mEntity.get().getPoint());
	mLocked = true;
}

void Camera::unlock()
{
	mLocked = false;
}

void Camera::setScale( screen::Scale const &scale )
{
	mScale = scale;
}

void Camera::changeScale( screen::Scale const &scale )
{
	if( scale.x > -mScale.x && scale.y > -mScale.y )
	{
		mScale += scale;
	}
}

std::queue< TransformedDrawable > Camera::getRenderQueue() const
{
	std::queue< TransformedDrawable > renderQueue;/*
	coldline::geometry::Vector3i iRelative = { 0, 0, ( int16_t )mPosition.z };
	coldline::geometry::Vector2f iScreen;
	for( iRelative.y = mPosition.y - ( mFov / mScale.y ), iScreen.y = 0;
		 iRelative.y <= ( int16_t )mPosition.y + ( mFov / mScale.y );
		 iRelative.y++, iScreen.y += 16.f * mScale.x ) //TODO
	{
		for( iRelative.x = mPosition.x - ( mFov / mScale.x ), iScreen.x = 0;
			 iRelative.x <= ( int16_t )mPosition.x + ( mFov / mScale.x );
			 iRelative.x++, iScreen.x += 16.f * mScale.x ) //TODO
		{
			screen::Scale scale = mScale * screen::Scale( 3.f, 3.f );
			if( iRelative.x < 0 || iRelative.y < 0 || iRelative.z < 0 ||
				!sees(( map::Point3 )iRelative ))
			{
				addDrawable( renderQueue, mNothing, iScreen, scale );
			}
			else
			{
				map::Point3 iMap = ( map::Point3 )iRelative;
				addDrawable( renderQueue,
					m.at( iMap ),
					( screen::Point )iScreen,
					scale );
				if( mMap.entityOn( iMap ))
				{
					addDrawable( renderQueue, mMap.getEntityOn( iMap ), iScreen, scale );
				}
			}
		}
	} TODO */ 
	return renderQueue;
}

void Camera::addDrawable( std::queue< TransformedDrawable > &renderQueue,
	sf::Drawable const &drawable,
	screen::Point const &point,
	screen::Scale const &scale )
{
	sf::Transform transform;
	transform.translate( static_cast< sf::Vector2f >( point ));
	transform.scale( static_cast< sf::Vector2f >( scale ));
	renderQueue.emplace( transform, drawable );
}

//TODO candidate for deletion
bool Camera::sees( map::Point3 const &what ) const
{
	return mWorld[ mPosition.location ].sees( mEntity.get().getPoint(), what );
}

}
