#include <data/dataMap.hpp>
#include "entitySubtype.hpp"

namespace coldline
{

EntitySubtype::EntitySubtype( Dataset const &dataset, DataMap const &dataMap ) :
	Sprite( dataset, dataMap ),
	mSolid( dataMap.getBool( "solid" ))
{

}

EntitySubtype::EntitySubtype( Sprite const &sprite, bool const &solid ) :
	Sprite( sprite ),
	mSolid( solid )
{

}

}
