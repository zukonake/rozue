#include <global.hpp>
#include <world/tile/tileSubtype.hpp>
#include "tile.hpp"

Tile::Tile() :
	mSubtype( nullptr )
{

}

Tile::Tile( Tile const &that ) :
	mSubtype( that.mSubtype )
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

Tile::Tile( TileSubtype const *subtype ) :
	mSubtype( subtype )
{
	
}

Sprite const &Tile::getSprite() const
{
	return *mSubtype;
}

bool Tile::passable() const
{
	return !mSubtype->mSolid;
}
