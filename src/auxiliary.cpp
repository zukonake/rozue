#include <data/dataMap.hpp>
#include <geometry/point.hpp>
#include <geometry/size.hpp>
#include "auxiliary.hpp"

namespace auxiliary
{

Point2 loadPoint2( DataMap const &dataMap )
{
	return
	{
		( uint16_t )dataMap.getInteger( 0 ),
		( uint16_t )dataMap.getInteger( 1 )
	};
}

Point3 loadPoint3( DataMap const &dataMap )
{
	return
	{
		( uint16_t )dataMap.getInteger( 0 ),
		( uint16_t )dataMap.getInteger( 1 ),
		( uint16_t )dataMap.getInteger( 2 )
	};
}

Size2 loadSize2( DataMap const &dataMap )
{
	return
	{
		( uint16_t )dataMap.getInteger( 0 ),
		( uint16_t )dataMap.getInteger( 1 )
	};
}

Size3 loadSize3( DataMap const &dataMap )
{
	return
	{
		( uint16_t )dataMap.getInteger( 0 ),
		( uint16_t )dataMap.getInteger( 1 ),
		( uint16_t )dataMap.getInteger( 2 )
	};
}

}
