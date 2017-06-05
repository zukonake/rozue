#include <world/tile/tileSubtype.hpp>
#include <render/tile.hpp>
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

render::Tile const &Tile::getRenderTile() const noexcept
{
	return mSubtype->mTile;
}

bool Tile::passable() const
{
	return !mSubtype->mSolid;
}

}
