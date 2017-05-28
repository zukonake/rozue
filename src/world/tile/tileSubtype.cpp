#include <data/dataMap.hpp>
#include "tileSubtype.hpp"

TileSubtype::TileSubtype( Dataset const &dataset, DataMap const &dataMap ) :
	Sprite( dataset, dataMap ),
	mSolid( dataMap.getBool( "solid" ))
{

}

TileSubtype::TileSubtype( Sprite const &sprite, bool const &solid ) :
	Sprite( sprite ),
	mSolid( solid )
{

}
