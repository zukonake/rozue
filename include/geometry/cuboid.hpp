/**
 * @file geometry/cuboid.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <geometry/vector3.hpp>
#include <geometry/line3.hpp>

namespace coldline
{

namespace geometry
{

template< typename TCoordinate, typename TLength >
struct Cuboid
{
	typedef Vector3< TCoordinate > Point;
	typedef Vector3< TLength > Size;
	typedef Vector3d Origin;
	typedef Line3< TLength > Diagonal;
	typedef TLength Volume;

	constexpr Cuboid() noexcept = default;
	constexpr Cuboid( Cuboid< TCoordinate, TLength > const &that ) noexcept = default;
	constexpr Cuboid( Point const &pos, Size const &size ) noexcept;
	template< typename TTCoordinate, typename TTLength >
	constexpr Cuboid( Cuboid< TTCoordinate, TTLength > const &that ) noexcept;

	template< typename TTCoordinate, typename TTLength >
	constexpr operator Cuboid< TTCoordinate, TTLength >() noexcept;

	constexpr Cuboid< TCoordinate, TLength > operator=( Cuboid< TCoordinate, TLength > const &that ) noexcept;

	constexpr bool operator==( Cuboid< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool operator!=( Cuboid< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool operator<=( Cuboid< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool operator>=( Cuboid< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool operator<( Cuboid< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool operator>( Cuboid< TCoordinate, TLength > const &that ) const noexcept;

	constexpr Diagonal getDiagonal() const noexcept;
	constexpr Volume getVolume() const noexcept;
	constexpr Origin getOrigin() const noexcept;
	constexpr Cuboid< TCoordinate, TLength > getBorder() const noexcept;
	constexpr bool touches( Cuboid< TCoordinate, TLength > const &that ) const noexcept;
	constexpr bool intersects( Cuboid< TCoordinate, TLength > const &that ) const noexcept;

	Point pos;
	Size size;

	TCoordinate &x = pos.x;
	TCoordinate &y = pos.y;
	TCoordinate &z = pos.z;
	TLength &w = size.x;
	TLength &h = size.y;
	TLength &d = size.z;
};



template< typename TCoordinate, typename TLength >
constexpr Cuboid< TCoordinate, TLength > Cuboid< TCoordinate, TLength >::operator=( Cuboid< TCoordinate, TLength > const &that ) noexcept
{
	pos = that.pos;
	size = that.size;
}

template< typename TCoordinate, typename TLength >
template< typename TTCoordinate, typename TTLength >
constexpr Cuboid< TCoordinate, TLength >::Cuboid( Cuboid< TTCoordinate, TTLength > const &that ) noexcept :
	pos(( Point )that.pos ),
	size(( Size )that.size )
{
	
}

template< typename TCoordinate, typename TLength >
template< typename TTCoordinate, typename TTLength >
constexpr Cuboid< TCoordinate, TLength >::operator Cuboid< TTCoordinate, TTLength >() noexcept
{
	return Cuboid< TTCoordinate, TTLength >( pos, size );
}

template< typename TCoordinate, typename TLength >
constexpr bool Cuboid< TCoordinate, TLength >::operator==( Cuboid< TCoordinate, TLength > const &that ) const noexcept
{
	return pos == that.pos && size == that.size;
}

template< typename TCoordinate, typename TLength >
constexpr bool Cuboid< TCoordinate, TLength >::operator!=( Cuboid< TCoordinate, TLength > const &that ) const noexcept
{
	return pos != that.pos || size != that.size;
}

template< typename TCoordinate, typename TLength >
constexpr bool Cuboid< TCoordinate, TLength >::operator<=( Cuboid< TCoordinate, TLength > const &that ) const noexcept
{
	return getVolume() <= that.getVolume();
}

template< typename TCoordinate, typename TLength >
constexpr bool Cuboid< TCoordinate, TLength >::operator>=( Cuboid< TCoordinate, TLength > const &that ) const noexcept
{
	return getVolume() >= that.getVolume();
}

template< typename TCoordinate, typename TLength >
constexpr bool Cuboid< TCoordinate, TLength >::operator<( Cuboid< TCoordinate, TLength > const &that ) const noexcept
{
	return getVolume() < that.getVolume();
}

template< typename TCoordinate, typename TLength >
constexpr bool Cuboid< TCoordinate, TLength >::operator>( Cuboid< TCoordinate, TLength > const &that ) const noexcept
{
	return getVolume() > that.getVolume();
}



template< typename TCoordinate, typename TLength >
constexpr Cuboid< TCoordinate, TLength > Cuboid< TCoordinate, TLength >::getBorder() const noexcept
{
	static_assert( std::is_integral< TCoordinate >::value &&
		std::is_integral< TLength >::value,
		"Cuboid must have parameters of integral type" );
	return Cuboid( pos - Point( 1, 1, 1 ), size + Size( 2, 2, 2 ));
}

template< typename TCoordinate, typename TLength >
constexpr typename Cuboid< TCoordinate, TLength >::Volume Cuboid< TCoordinate, TLength >::getVolume() const noexcept
{
	return w * h * d;
}

template< typename TCoordinate, typename TLength >
constexpr typename Cuboid< TCoordinate, TLength >::Origin Cuboid< TCoordinate, TLength >::getOrigin() const noexcept
{
	return { x + ( w / 2.0 ), y + ( h / 2.0 ), z + ( d / 2.0 )};
}

template< typename TCoordinate, typename TLength >
constexpr bool Cuboid< TCoordinate, TLength >::touches( Cuboid< TCoordinate, TLength > const &that ) const noexcept
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
constexpr bool Cuboid< TCoordinate, TLength >::intersects( Cuboid< TCoordinate, TLength > const &that ) const noexcept
{
	return ( x < that.x + that.w &&
			 y < that.y + that.h &&
			 z < that.z + that.d &&
			 x + w > that.x &&
			 y + h > that.y &&
			 z + d > that.z );
}

}

}
