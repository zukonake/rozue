#include <SFML/Graphics/RenderTarget.hpp>
//
#include <world/tile/tileSubtype.hpp>
#include "tile.hpp"

namespace coldline
{

Tile::Tile() :
	mSubtype( nullptr )
{

}

Tile::Tile( Tile const &that ) :
	mSubtype( that.mSubtype )
{

}

Tile::Tile( TileSubtype const &subtype ) :
	mSubtype( &subtype )
{
	
}

Tile &Tile::operator=( Tile const &that )
{
	mSubtype = that.mSubtype;
	return *this;
}

Tile &Tile::operator=( TileSubtype const &that )
{
	mSubtype = &that;
	return *this;
}

void Tile::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	target.draw( *mSubtype, states );
}

bool Tile::passable() const
{
	return !mSubtype->mSolid;
}

}
