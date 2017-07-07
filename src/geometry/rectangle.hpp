/**
 * @file geometry/rectangle.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <geometry/vector2.hpp>
#include <geometry/line2.hpp>

namespace geometry
{

template< typename TCoordinate, typename TLength >
struct Rectangle
{
	typedef Vector2< TCoordinate > Point;
	typedef Vector2< TLength > Size;
	typedef Vector2< double > Origin;
	typedef Line2< TLength > Diagonal;
	typedef TLength Area;

	constexpr Rectangle() noexcept = default;
	constexpr Rectangle< TCoordinate, TLength > operator=( Rectangle< TCoordinate, TLength > const &that ) noexcept;
	constexpr Rectangle( Point const &pos, Size const &size ) noexcept;
	//TODO converions?

	constexpr bool operator==( Rectangle< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool operator!=( Rectangle< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool operator<=( Rectangle< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool operator>=( Rectangle< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool operator<( Rectangle< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool operator>( Rectangle< TCoordinate, TLength > const &that ) const noexcept;

	constexpr Diagonal getDiagonal() const noexcept;
	constexpr Area getArea() const noexcept;
	constexpr Origin getOrigin() const noexcept;
	constexpr Rectangle< TCoordinate, TLength > getBorder() const noexcept;
	constexpr bool touches( Rectangle< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool intersects( Rectangle< TCoordinate, TLength > const &that ) const noexcept;

	Point pos;
	Size size;

	TCoordinate &x = pos.x;
	TCoordinate &y = pos.y;
	TLength &w = size.x;
	TLength &h = size.y;
};



template< typename TCoordinate, typename TLength >
constexpr Rectangle< TCoordinate, TLength >::Rectangle( Point const &pos, Size const &size ) noexcept :
	pos( pos ),
	size( size )
{
	
}



template< typename TCoordinate, typename TLength >
constexpr Rectangle< TCoordinate, TLength > Rectangle< TCoordinate, TLength >::operator=( Rectangle< TCoordinate, TLength > const &that ) noexcept
{
	pos = that.pos;
	size = that.size;
}

template< typename TCoordinate, typename TLength >
constexpr bool Rectangle< TCoordinate, TLength >::operator==( Rectangle< TCoordinate, TLength > const &that ) const noexcept
{
	return pos == that.pos && size == that.size;
}

template< typename TCoordinate, typename TLength >
constexpr bool Rectangle< TCoordinate, TLength >::operator!=( Rectangle< TCoordinate, TLength > const &that ) const noexcept
{
	return pos != that.pos || size != that.size;
}

template< typename TCoordinate, typename TLength >
constexpr bool Rectangle< TCoordinate, TLength >::operator<=( Rectangle< TCoordinate, TLength > const &that ) const noexcept
{
	return getArea() <= that.getArea();
}

template< typename TCoordinate, typename TLength >
constexpr bool Rectangle< TCoordinate, TLength >::operator>=( Rectangle< TCoordinate, TLength > const &that ) const noexcept
{
	return getArea() >= that.getArea();
}

template< typename TCoordinate, typename TLength >
constexpr bool Rectangle< TCoordinate, TLength >::operator<( Rectangle< TCoordinate, TLength > const &that ) const noexcept
{
	return getArea() < that.getArea();
}

template< typename TCoordinate, typename TLength >
constexpr bool Rectangle< TCoordinate, TLength >::operator>( Rectangle< TCoordinate, TLength > const &that ) const noexcept
{
	return getArea() > that.getArea();
}



template< typename TCoordinate, typename TLength >
constexpr Rectangle< TCoordinate, TLength > Rectangle< TCoordinate, TLength >::getBorder() const noexcept
{
	static_assert( std::is_integral< TCoordinate >::value &&
		std::is_integral< TLength >::value,
		"Rectangle must have parameters of integral type" );
	return Rectangle( pos - Point( 1, 1 ), size + Size( 2, 2 ));
}

template< typename TCoordinate, typename TLength >
constexpr typename Rectangle< TCoordinate, TLength >::Area Rectangle< TCoordinate, TLength >::getArea() const noexcept
{
	return w * h;
}

template< typename TCoordinate, typename TLength >
constexpr typename Rectangle< TCoordinate, TLength >::Origin Rectangle< TCoordinate, TLength >::getOrigin() const noexcept
{
	return { x + ( w / 2.0 ), y + ( h / 2.0 )};
}

template< typename TCoordinate, typename TLength >
constexpr bool Rectangle< TCoordinate, TLength >::touches( Rectangle< TCoordinate, TLength > const &that ) const noexcept
{
	if( std::is_integral< TCoordinate >::value && std::is_integral< TLength >::value )
	{
		return getBorder().intersects( that );
	}
	else
	{
		return intersects( that );
	}
}

template< typename TCoordinate, typename TLength >
constexpr bool Rectangle< TCoordinate, TLength >::intersects( Rectangle< TCoordinate, TLength > const &that ) const noexcept
{
	return ( x < that.x + that.w &&
			 y < that.y + that.h &&
			 x + w > that.x &&
			 y + h > that.y );
}

}
