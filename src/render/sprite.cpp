#include <SFML/Graphics.hpp>
//
#include <data/dataMap.hpp>
#include <data/dataset.hpp>
#include <render/tileset.hpp>
#include "sprite.hpp"

namespace coldline
{

Sprite::Sprite( Dataset const &dataset, DataMap const &dataMap ) :
	mTileset( dataset.at< Tileset >( dataMap.getString( "tileset" ))),
	mTilesetPosition( dataMap.toVector2< screen::Coordinate >())
{

}

Sprite::Sprite( Tileset const &tileset, screen::Point const &tilesetPosition ) :
	mTileset( tileset ),
	mTilesetPosition( tilesetPosition )
{

}

void Sprite::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	states.texture = &mTileset.getTexture();
	sf::VertexArray square( sf::Quads, 4 );
	screen::Size spriteSize = mTileset.getTileSize();

	square[ 0 ].position =
	{
		0 * spriteSize.x,
		0 * spriteSize.y
	};
	square[ 1 ].position =
	{
		1 * spriteSize.x,
		0 * spriteSize.y
	};
	square[ 2 ].position =
	{
		1 * spriteSize.x,
		1 * spriteSize.y
	};
	square[ 3 ].position =
	{
		0 * spriteSize.x,
		1 * spriteSize.y
	};

	square[ 0 ].texCoords =
	{
		( mTilesetPosition.x + 0 ) * spriteSize.x,
		( mTilesetPosition.y + 0 ) * spriteSize.y
	};
	square[ 1 ].texCoords =
	{
		( mTilesetPosition.x + 1 ) * spriteSize.x,
		( mTilesetPosition.y + 0 ) * spriteSize.y
	};
	square[ 2 ].texCoords =
	{
		( mTilesetPosition.x + 1 ) * spriteSize.x,
		( mTilesetPosition.y + 1 ) * spriteSize.y
	};
	square[ 3 ].texCoords =
	{
		( mTilesetPosition.x + 0 ) * spriteSize.x,
		( mTilesetPosition.y + 1 ) * spriteSize.y
	};

	target.draw( square, states );
}

screen::Size const &Sprite::getSize() const noexcept
{
	return mTileset.getTileSize();
}

}
