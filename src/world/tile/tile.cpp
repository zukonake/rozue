#include <world/tile/tileSubtype.hpp>
#include "tile.hpp"

namespace coldline
{

Tile::Tile( Tile const &that ) noexcept :
	mSubtype( that.mSubtype )
{

}

Tile::Tile( TileSubtype const &subtype ) noexcept :
	mSubtype( &subtype )
{
	
}

Tile &Tile::operator=( Tile const &that ) noexcept
{
	mSubtype = that.mSubtype;
	return *this;
}

Tile &Tile::operator=( TileSubtype const &that ) noexcept
{
	mSubtype = &that;
	return *this;
}

render::Tile const &Tile::getRenderTile() const noexcept
{
	return mSubtype->mRenderTile;
}

bool Tile::passable() const noexcept
{
	return !mSubtype->mSolid;
}

}
