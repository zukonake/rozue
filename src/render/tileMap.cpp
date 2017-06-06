#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
//
#include <render/tileset.hpp>
#include "tileMap.hpp"

namespace coldline
{

TileMap::TileMap(
	render::Size const &spriteSize,
	render::Size const &screenSize,
	Tileset const *tileset ) :
		mSpriteSize( spriteSize ),
		mScreenSize( screenSize ),
		mTileset( tileset )
{
	mVertices.setPrimitiveType( sf::Quads );
	updateSize();
}



void TileMap::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	states.texture = &mTileset->getTexture();
	target.draw( mVertices, states );
}



void TileMap::update( Tiles const &tiles )
{
	for( unsigned iY = 0; iY < mSize.y; iY++ )
	{
		for( unsigned iX = 0; iX < mSize.x; iX++ )
		{
			sf::Vertex *quad = &mVertices[( iX + ( iY * mSize.x )) * 4];

			render::Size tileSize = mTileset->getTileSize();
			render::Point const &tilePosition = tiles[ iY ][ iX ];

			quad[ 0 ].position =
			{
				0 * iX * mSpriteSize.x,
				0 * iY * mSpriteSize.y
			};
			quad[ 1 ].position =
			{
				1 * iX * mSpriteSize.x,
				0 * iY * mSpriteSize.y
			};
			quad[ 2 ].position =
			{
				1 * iX * mSpriteSize.x,
				1 * iY * mSpriteSize.y
			};
			quad[ 3 ].position =
			{
				0 * iX * mSpriteSize.x,
				1 * iY * mSpriteSize.y
			};

			quad[ 0 ].texCoords =
			{
				( tilePosition.x + 0 ) * iX * tileSize.x,
				( tilePosition.y + 0 ) * iY * tileSize.y
			};
			quad[ 1 ].texCoords =
			{
				( tilePosition.x + 1 ) * iX * tileSize.x,
				( tilePosition.y + 0 ) * iY * tileSize.y
			};
			quad[ 2 ].texCoords =
			{
				( tilePosition.x + 1 ) * iX * tileSize.x,
				( tilePosition.y + 1 ) * iY * tileSize.y
			};
			quad[ 3 ].texCoords =
			{
				( tilePosition.x + 0 ) * iX * tileSize.x,
				( tilePosition.y + 1 ) * iY * tileSize.y
			};
		}
	}
}



void TileMap::setSpriteSize( render::Size const &spriteSize )
{
	mSpriteSize = spriteSize;
	updateSize();
}

void TileMap::setScreenSize( render::Size const &screenSize )
{
	mScreenSize = screenSize;
	updateSize();
}

void TileMap::setTileset( Tileset const *tileset )
{
	mTileset = tileset;
}



void TileMap::updateSize()
{
	mSize = 
	{
		( mScreenSize.x / mSpriteSize.x ) + 2,
		( mScreenSize.y / mSpriteSize.y ) + 2
	};
	mVertices.resize( mSize.x * mSize.y * 4 );
}

}
