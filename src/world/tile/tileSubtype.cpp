#include <data/dataMap.hpp>
#include "tileSubtype.hpp"

namespace coldline
{

TileSubtype::TileSubtype( Dataset const &dataset, DataMap const &dataMap ) :
	mRenderTile( dataset, dataMap ),
	mSolid( dataMap.getBool( "solid" ))
{

}

TileSubtype::TileSubtype( render::Tile const &renderTile, bool const &solid ) noexcept :
	mRenderTile( renderTile ),
	mSolid( solid )
{

}

}
