#include <global.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/entity/entitySubtype.hpp>
#include <world/world.hpp>
#include "entity.hpp"

Entity::Entity( World &world, Point const &position, EntitySubtype const &subtype ) :
	mWorld( world ),
	mPosition( position ),
	subtype( subtype )
{

}

void Entity::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	sf::VertexArray square( sf::Quads, 4 );

	square[ 0 ].position =
		{ 0,
		  0 };
	square[ 1 ].position =
		{ global::textureSpriteSize.x,
		  0 };
	square[ 2 ].position =
		{ global::textureSpriteSize.x,
		  global::textureSpriteSize.y };
	square[ 3 ].position =
		{ 0,
		  global::textureSpriteSize.y };

	square[ 0 ].texCoords =
		{ subtype.tilesetPosition.x + 0,
		  subtype.tilesetPosition.y + 0 };
	square[ 1 ].texCoords =
		{ subtype.tilesetPosition.x + global::textureSpriteSize.x,
		  subtype.tilesetPosition.y + 0 };
	square[ 2 ].texCoords =
		{ subtype.tilesetPosition.x + global::textureSpriteSize.x,
		  subtype.tilesetPosition.y + global::textureSpriteSize.y };
	square[ 3 ].texCoords =
		{ subtype.tilesetPosition.x + 0,
		  subtype.tilesetPosition.y + global::textureSpriteSize.y };

	target.draw( square, states );
}

bool Entity::move( Vector const &by )
{
	Point newPosition = mPosition + by;
	if( World::exists( newPosition )) 
	{
		if( !mWorld[ newPosition ].subtype->solid )
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
		if( !mWorld[ to ].subtype->solid )
		{
			mPosition = to; //TODO check with pathfind
			return true;
		}
	}
	return false;
}

Point const &Entity::getPosition() const noexcept
{
	return mPosition;
}
