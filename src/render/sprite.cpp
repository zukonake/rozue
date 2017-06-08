#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
//
#include <render/tileset.hpp>
#include <render/tile.hpp>
#include "sprite.hpp"

namespace coldline
{

Sprite::Sprite(
	render::Surface const &surface,
	render::Tile const &tile,
	sf::Color const &color )
{
	setTile( tile );
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

void Sprite::setSurface( render::Surface const &surface )
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

void Sprite::setTile( render::Tile const &tile )
{
	mTileset = &tile.tileset;
	render::Size tileSize = mTileset->getTileSize();

	mVertices[ 0 ].texCoords =
	{
		( tile.tilesetPosition.x + 0 ) * tileSize.x,
		( tile.tilesetPosition.y + 0 ) * tileSize.y
	};
	mVertices[ 1 ].texCoords =
	{
		( tile.tilesetPosition.x + 1 ) * tileSize.x,
		( tile.tilesetPosition.y + 0 ) * tileSize.y
	};
	mVertices[ 2 ].texCoords =
	{
		( tile.tilesetPosition.x + 1 ) * tileSize.x,
		( tile.tilesetPosition.y + 1 ) * tileSize.y
	};
	mVertices[ 3 ].texCoords =
	{
		( tile.tilesetPosition.x + 0 ) * tileSize.x,
		( tile.tilesetPosition.y + 1 ) * tileSize.y
	};
}

}
