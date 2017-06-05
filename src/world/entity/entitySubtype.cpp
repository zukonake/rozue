#include <data/dataMap.hpp>
#include "entitySubtype.hpp"

namespace coldline
{

EntitySubtype::EntitySubtype( Dataset const &dataset, DataMap const &dataMap ) :
	mTile( dataset, dataMap ),
	mSolid( dataMap.getBool( "solid" ))
{

}

EntitySubtype::EntitySubtype( render::Tile const &renderTile, bool const &solid ) :
	mTile( renderTile ),
	mSolid( solid )
{

}

}
