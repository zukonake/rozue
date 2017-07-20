/**
 * @file geometry/Line3.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <cmath>
#include <vector>
//
#include <geometry/Vector3D.hpp>

namespace geometry
{

template< typename TCoordinate >
struct Line3D
{
	typedef Vector3D< TCoordinate > Point;
	typedef Vector3D< double > Center;
	typedef std::vector< Point > Plot;
	typedef double Length;

	constexpr Line3D() noexcept = default;
	constexpr Line3D( Line3D const &that ) noexcept = default;
	constexpr Line3D( Point const &from, Point const &to ) noexcept;
	template < typename TTCoordinate >
	constexpr Line3D( Line3D< TTCoordinate > const &that ) noexcept;

	template< typename TTCoordinate >
	constexpr operator Line3D< TTCoordinate >() const noexcept;

	constexpr Line3D< TCoordinate > operator+( Line3D< TCoordinate > const &that );
	constexpr Line3D< TCoordinate > operator-( Line3D< TCoordinate > const &that );

	constexpr Line3D< TCoordinate > &operator+=( Line3D< TCoordinate > const &that );
	constexpr Line3D< TCoordinate > &operator-=( Line3D< TCoordinate > const &that );

	constexpr bool operator==( Line3D< TCoordinate > const &that );
	constexpr bool operator!=( Line3D< TCoordinate > const &that );
	constexpr bool operator<=( Line3D< TCoordinate > const &that );
	constexpr bool operator>=( Line3D< TCoordinate > const &that );
	constexpr bool operator<( Line3D< TCoordinate > const &that );
	constexpr bool operator>( Line3D< TCoordinate > const &that );

	constexpr Length getLength() const noexcept;
	constexpr Center getCenter() const noexcept;
	Plot getPlot() const noexcept;
	Plot getBounds() const noexcept;

	Point from;
	Point to;
};



template< typename TCoordinate >
constexpr Line3D< TCoordinate >::Line3D( Point const &from, Point const &to ) noexcept :
	from( from ),
	to( to )
{

}

template< typename TCoordinate >
template< typename TTCoordinate >
constexpr Line3D< TCoordinate >::Line3D( Line3D< TTCoordinate > const &that ) noexcept :
	from( static_cast< Point >( that.from )),
	to( static_cast< Point >( that.to ))
{
	
}



template< typename TCoordinate >
template< typename TTCoordinate >
constexpr Line3D< TCoordinate >::operator Line3D< TTCoordinate >() const noexcept
{
	return Line3D< TTCoordinate >( from, to );
}



template< typename TCoordinate >
constexpr Line3D< TCoordinate > Line3D< TCoordinate >::operator+( Line3D< TCoordinate > const &that )
{
	return Line3D< TCoordinate >( from + that.from, to + that.to );
}

template< typename TCoordinate >
constexpr Line3D< TCoordinate > Line3D< TCoordinate >::operator-( Line3D< TCoordinate > const &that )
{
	return Line3D< TCoordinate >( from - that.from, to - that.to );
}

template< typename TCoordinate >
constexpr Line3D< TCoordinate > &Line3D< TCoordinate >::operator+=( Line3D< TCoordinate > const &that )
{
	from += that.from;
	to += that.to;
	return *this;
}

template< typename TCoordinate >
constexpr Line3D< TCoordinate > &Line3D< TCoordinate >::operator-=( Line3D< TCoordinate > const &that )
{
	from -= that.from;
	to -= that.to;
	return *this;
}



template< typename TCoordinate >
constexpr bool Line3D< TCoordinate >::operator==( Line3D< TCoordinate > const &that )
{
	return from == that.from && to == that.to;
}

template< typename TCoordinate >
constexpr bool Line3D< TCoordinate >::operator!=( Line3D< TCoordinate > const &that )
{
	return from != that.from || to != that.to;
}

template< typename TCoordinate >
constexpr bool Line3D< TCoordinate >::operator<=( Line3D< TCoordinate > const &that )
{
	return getLength() <= that.getLength();
}

template< typename TCoordinate >
constexpr bool Line3D< TCoordinate >::operator>=( Line3D< TCoordinate > const &that )
{
	return getLength() >= that.getLength();
}

template< typename TCoordinate >
constexpr bool Line3D< TCoordinate >::operator<( Line3D< TCoordinate > const &that )
{
	return getLength() < that.getLength();
}

template< typename TCoordinate >
constexpr bool Line3D< TCoordinate >::operator>( Line3D< TCoordinate > const &that )
{
	return getLength() > that.getLength();
}

template< typename TCoordinate >
constexpr typename Line3D< TCoordinate >::Length Line3D< TCoordinate >::getLength() const noexcept
{
	return from.getDistance( to );
}

template< typename TCoordinate >
constexpr typename Line3D< TCoordinate >::Center Line3D< TCoordinate >::getCenter() const noexcept
{
	return Line3D< TCoordinate >( from + getLength() / 2.f, to + getLength() / 2.f );
}

template< typename TCoordinate >
typename Line3D< TCoordinate >::Plot Line3D< TCoordinate >::getPlot() const noexcept
{
	Plot plot;
	Point temp = from;

	signed long deltaX( to.x - temp.x );
	signed short const iX(( deltaX > 0 ) - ( deltaX < 0 ));
	deltaX = std::abs( deltaX ) << 1;

	signed long deltaY( to.y - temp.y );
	signed short const iY(( deltaY > 0 ) - ( deltaY < 0 ));
	deltaY = std::abs( deltaY ) << 1;
/*
	signed long deltaZ( to.z - temp.z );
	signed short const iZ(( deltaZ > 0 ) - ( deltaZ < 0 ));
	deltaZ = std::abs( deltaZ ) << 1;*/
	
	plot.push_back( temp );
//TODO i guess
	if( deltaX >= deltaY )
	{
		signed long error( deltaY - ( deltaX >> 1 ));

		while( temp.x != to.x )
		{
			if(( error >= 0 ) && ( error || ( iX > 0 )))
			{
				error -= deltaX;
				temp.y += iY;
			}

			error += deltaY;
			temp.x += iX;

			plot.push_back( temp );
		}
	}
	else
	{
		signed long error( deltaX - ( deltaY >> 1 ));
 
		while( temp.y != to.y )
		{
			if(( error >= 0 ) && ( error || ( iY > 0 )))
			{
				error -= deltaY;
				temp.x += iX;
			}

			error += deltaX;
			temp.y += iY;
 
			plot.push_back( temp );
		}
	}
	return plot;
}
/* TODO
template< typename TCoordinate >
typename Line3D< TCoordinate >::Plot Line3D< TCoordinate >::getBounds() const noexcept
{
	Plot bounds;
	return bounds;
}*/

}
