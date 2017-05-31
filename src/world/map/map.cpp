#include <world/tile/tile.hpp>
#include "map.hpp"

namespace coldline
{

bool Map::sees( map::Point3 const &from, map::Point3 const &to )
{
	if( !exists( to ) || !exists( from ))
	{
		return false;
	}
	auto plot = map::Line3( from, to ).getPlot();
	if( plot.empty())
	{
		return false;
	}
	for( unsigned i = 1; i < plot.size() - 1; i++ )
	{
		if( !this->operator[]( plot[ i ]).passable())
		{
			return false;
		}
		if( entityOn( plot[ i ]))
		{
			if( getEntityOn( plot[ i ]).passable())
			{
				return false;
			}
		}
	}
	return true;
}

bool Map::sees( map::Point3 const &from, map::Point3 const &to ) const
{
	if( !exists( to ) || !exists( from ))
	{
		return false;
	}
	auto plot = map::Line3( from, to ).getPlot();
	if( plot.empty())
	{
		return false;
	}
	for( unsigned i = 1; i < plot.size() - 1; i++ )
	{
		if( !this->operator[]( plot[ i ]).passable())
		{
			return false;
		}
		if( entityOn( plot[ i ]))
		{
			if( getEntityOn( plot[ i ]).passable())
			{
				return false;
			}
		}
	}
	return true;
}

}
