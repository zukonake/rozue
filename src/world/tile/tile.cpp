#include <global.hpp>
#include <world/tile/tileSubtype.hpp>
#include "tile.hpp"

Tile::Tile() :
	subtype( nullptr )
{

}

Tile::Tile( Tile const &that ) :
	subtype( that.subtype )
{

}

Tile &Tile::operator=( Tile const &that )
{
	subtype = that.subtype;
	return *this;
}

Tile::Tile( TileSubtype const *subtype ) :
	subtype( subtype )
{
	
}

void Tile::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	sf::VertexArray square( sf::Quads, 4 );

	square[ 0 ].position =
		{ 0,
		  0 };
	square[ 1 ].position =
		{ global::spriteSize.x,
		  0 };
	square[ 2 ].position =
		{ global::spriteSize.x,
		  global::spriteSize.y };
	square[ 3 ].position =
		{ 0,
		  global::spriteSize.y };

	square[ 0 ].texCoords =
		{ subtype->tilesetPosition.x + 0,
		  subtype->tilesetPosition.y + 0 };
	square[ 1 ].texCoords =
		{ subtype->tilesetPosition.x + global::spriteSize.x,
		  subtype->tilesetPosition.y + 0 };
	square[ 2 ].texCoords =
		{ subtype->tilesetPosition.x + global::spriteSize.x,
		  subtype->tilesetPosition.y + global::spriteSize.y };
	square[ 3 ].texCoords =
		{ subtype->tilesetPosition.x + 0,
		  subtype->tilesetPosition.y + global::spriteSize.y };

	target.draw( square, states );
}

bool Tile::passable() const
{
	return subtype->solid;
}
