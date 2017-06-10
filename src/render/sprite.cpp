#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
//
#include <render/tileset.hpp>
#include <render/renderTile.hpp>
#include "sprite.hpp"

namespace coldline
{

Sprite::Sprite(
	RenderSurface const &surface,
	RenderTile const &renderTile,
	sf::Color const &color )
{
	setRenderTile( renderTile );
	setSurface( surface );
	setColor( color );
}

void Sprite::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	states.texture = &mTileset->getTexture();
	target.draw( mVertices, 4, sf::Quads, states );
}

void Sprite::setColor( sf::Color const &color )
{
	mVertices[ 0 ].color = color;
	mVertices[ 1 ].color = color;
	mVertices[ 2 ].color = color;
	mVertices[ 3 ].color = color;
}

void Sprite::setSurface( RenderSurface const &surface )
{
	mVertices[ 0 ].position =
	{
		( 0 * surface.w ) + surface.x,
		( 0 * surface.h ) + surface.y
	};
	mVertices[ 1 ].position =
	{
		( 1 * surface.w ) + surface.x,
		( 0 * surface.h ) + surface.y
	};
	mVertices[ 2 ].position =
	{
		( 1 * surface.w ) + surface.x,
		( 1 * surface.h ) + surface.y
	};
	mVertices[ 3 ].position =
	{
		( 0 * surface.w ) + surface.x,
		( 1 * surface.h ) + surface.y
	};
}

void Sprite::setRenderTile( RenderTile const &renderTile )
{
	mTileset = &renderTile.tileset;
	RenderSize tileSize = mTileset->getTileSize();

	mVertices[ 0 ].texCoords =
	{
		( renderTile.tilesetPosition.x + 0 ) * tileSize.x,
		( renderTile.tilesetPosition.y + 0 ) * tileSize.y
	};
	mVertices[ 1 ].texCoords =
	{
		( renderTile.tilesetPosition.x + 1 ) * tileSize.x,
		( renderTile.tilesetPosition.y + 0 ) * tileSize.y
	};
	mVertices[ 2 ].texCoords =
	{
		( renderTile.tilesetPosition.x + 1 ) * tileSize.x,
		( renderTile.tilesetPosition.y + 1 ) * tileSize.y
	};
	mVertices[ 3 ].texCoords =
	{
		( renderTile.tilesetPosition.x + 0 ) * tileSize.x,
		( renderTile.tilesetPosition.y + 1 ) * tileSize.y
	};
}

}
