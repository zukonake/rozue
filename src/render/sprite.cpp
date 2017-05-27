#include <SFML/Graphics.hpp>
//
#include <data/dataMap.hpp>
#include <data/dataset.hpp>
#include <auxiliary.hpp>
#include <render/tileset.hpp>
#include "sprite.hpp"

Sprite::Sprite( Dataset const &dataset, DataMap const &dataMap ) :
	mTileset( dataset.at< Tileset >( dataMap.getString( "tileset" ))),
	mTilesetPosition( auxiliary::loadPoint2( dataMap ))
{

}

Sprite::Sprite( Tileset const &tileset, Point2 const &tilesetPosition ) :
	mTileset( tileset ),
	mTilesetPosition( tilesetPosition )
{

}

void Sprite::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	states.texture = &mTileset.getTexture();
	sf::VertexArray square( sf::Quads, 4 );

	square[ 0 ].position =
	{
		0.f * mTileset.getSpriteSize().x,
		0.f * mTileset.getSpriteSize().y
	};
	square[ 1 ].position =
	{
		1.f * mTileset.getSpriteSize().x,
		0.f * mTileset.getSpriteSize().y
	};
	square[ 2 ].position =
	{
		1.f * mTileset.getSpriteSize().x,
		1.f * mTileset.getSpriteSize().y
	};
	square[ 3 ].position =
	{
		0.f * mTileset.getSpriteSize().x,
		1.f * mTileset.getSpriteSize().y
	};

	square[ 0 ].texCoords =
	{
		(( float )mTilesetPosition.x + 0.f ) * mTileset.getSpriteSize().x,
		(( float )mTilesetPosition.y + 0.f ) * mTileset.getSpriteSize().y
	};
	square[ 1 ].texCoords =
	{
		(( float )mTilesetPosition.x + 1.f ) * mTileset.getSpriteSize().x,
		(( float )mTilesetPosition.y + 0.f ) * mTileset.getSpriteSize().y
	};
	square[ 2 ].texCoords =
	{
		(( float )mTilesetPosition.x + 1.f ) * mTileset.getSpriteSize().x,
		(( float )mTilesetPosition.y + 1.f ) * mTileset.getSpriteSize().y
	};
	square[ 3 ].texCoords =
	{
		(( float )mTilesetPosition.x + 0.f ) * mTileset.getSpriteSize().x,
		(( float )mTilesetPosition.y + 1.f ) * mTileset.getSpriteSize().y
	};

	target.draw( square, states );
}

Sprite const &Sprite::getSprite() const
{
	return *this;
}

Size2 const &Sprite::getSize() const noexcept
{
	return mTileset.getSpriteSize();
}
