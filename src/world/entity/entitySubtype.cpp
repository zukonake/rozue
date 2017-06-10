#include <data/dataMap.hpp>
#include "entitySubtype.hpp"

namespace coldline
{

EntitySubtype::EntitySubtype( Dataset const &dataset, DataMap const &dataMap ) :
	mRenderTile( dataset, dataMap ),
	mSolid( dataMap.getBool( "solid" ))
{

}

EntitySubtype::EntitySubtype( RenderTile const &renderTile, bool const &solid ) noexcept :
	mRenderTile( renderTile ),
	mSolid( solid )
{

}

}
