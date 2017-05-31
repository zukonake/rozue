/**
 * @file geometry/line2.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <cmath>
#include <vector>
//
#include <geometry/vector2.hpp>

namespace coldline
{

namespace geometry
{

template< typename TCoordinate >
struct Line2
{
	typedef Vector2< TCoordinate > Point;
	typedef Vector2< double > Center;
	typedef std::vector< Point > Plot;
	typedef double Length;

	constexpr Line2() noexcept = default;
	constexpr Line2( Line2 const &that ) noexcept = default;
	constexpr Line2( Point const &from, Point const &to ) noexcept;
	template < typename T >
	constexpr Line2( Line2< T > const &that ) noexcept;

	template< typename T >
	constexpr operator Line2< T >();

	constexpr Line2< TCoordinate > &operator=( Line2 const &that );
	constexpr Line2< TCoordinate > &operator+( Line2 const &that );
	constexpr Line2< TCoordinate > &operator-( Line2 const &that );

	constexpr Line2< TCoordinate > &operator+=( Line2 const &that );
	constexpr Line2< TCoordinate > &operator-=( Line2 const &that );

	constexpr bool operator==( Line2 const &that );
	constexpr bool operator!=( Line2 const &that );
	constexpr bool operator<=( Line2 const &that );
	constexpr bool operator>=( Line2 const &that );
	constexpr bool operator<( Line2 const &that );
	constexpr bool operator>( Line2 const &that );

	constexpr Length getLength() const noexcept;
	constexpr Center getCenter() const noexcept;
	Plot getPlot() const noexcept;
	Plot getBounds() const noexcept;

	Point from;
	Point to;
};

/*
std::vector< Point3 > plotLine( Point3 const &from, Point3 const &to )
{
	std::vector< Point3 > line;
	if( from.z != to.z )
	{
		return line;
	}
	Point3 temp = from;

	int16_t deltaX( to.x - temp.x );
	signed char const iX(( deltaX > 0 ) - ( deltaX < 0 ));
	deltaX = std::abs( deltaX ) << 1;

	int deltaY( to.y - temp.y );
	signed char const iY(( deltaY > 0 ) - ( deltaY < 0 ));
	deltaY = std::abs( deltaY ) << 1;
	
	line.push_back( temp );

	if( deltaX >= deltaY )
	{
		int16_t error( deltaY - ( deltaX >> 1 ));

		while( temp.x != to.x )
		{
			if(( error >= 0 ) && ( error || ( iX > 0 )))
			{
				error -= deltaX;
				temp.y += iY;
			}

			error += deltaY;
			temp.x += iX;

			line.push_back( temp );
		}
	}
	else
	{
		int16_t error( deltaX - ( deltaY >> 1 ));
 
		while( temp.y != to.y )
		{
			if(( error >= 0 ) && ( error || ( iY > 0 )))
			{
				error -= deltaY;
				temp.x += iX;
			}
	
			error += deltaX;
			temp.y += iY;
 
			line.push_back( temp );
		}
	}
	return line;
}

}*/

}

}
