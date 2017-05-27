#include <data/dataMap.hpp>
#include "entitySubtype.hpp"

EntitySubtype::EntitySubtype( Dataset const &dataset, DataMap const &dataMap ) :
	Sprite( dataset, dataMap )
{

}

EntitySubtype::EntitySubtype( Sprite const &sprite ) :
	Sprite( sprite )
{

}
