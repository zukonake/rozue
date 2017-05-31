/*
 * @file geometry/vector3.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <type_traits>
#include <functional>
//
#include <geometry/vector2.hpp>

namespace coldline
{

namespace geometry
{

template< typename T >
struct Vector3;

typedef Vector3< short > Vector3s;
typedef Vector3< unsigned short > Vector3us;
typedef Vector3< int > Vector3i;
typedef Vector3< unsigned > Vector3u;
typedef Vector3< long > Vector3l;
typedef Vector3< unsigned long > Vector3ul;
typedef Vector3< long long > Vector3ll;
typedef Vector3< unsigned long long > Vector3ull;
typedef Vector3< float > Vector3f;
typedef Vector3< double > Vector3d;
typedef Vector3< long double > Vector3ld;

template< typename T >
struct Vector3
{
	constexpr Vector3() noexcept;
	constexpr Vector3( T const &x, T const &y, T const &z ) noexcept;
	constexpr Vector3( Vector2< T > const &xy, T const &z ) noexcept;
	template< typename U >
	constexpr explicit Vector3( U const &that );

	template< typename U > //TODO from vector3< U >
	constexpr explicit operator U() const;

	constexpr Vector3< T > operator*( Vector3< T > const &that ) const noexcept;
	constexpr Vector3< T > operator/( Vector3< T > const &that ) const noexcept;
	constexpr Vector3< T > operator+( Vector3< T > const &that ) const noexcept;
	constexpr Vector3< T > operator-( Vector3< T > const &that ) const noexcept;

	constexpr Vector3< T > &operator*=( Vector3< T > const &that ) noexcept;
	constexpr Vector3< T > &operator/=( Vector3< T > const &that ) noexcept;
	constexpr Vector3< T > &operator+=( Vector3< T > const &that ) noexcept;
	constexpr Vector3< T > &operator-=( Vector3< T > const &that ) noexcept;

	constexpr bool operator==( Vector3< T > const &that ) const noexcept;
	constexpr bool operator!=( Vector3< T > const &that ) const noexcept;
	constexpr bool operator<=( Vector3< T > const &that ) const noexcept;
	constexpr bool operator>=( Vector3< T > const &that ) const noexcept;
	constexpr bool operator<( Vector3< T > const &that ) const noexcept;
	constexpr bool operator>( Vector3< T > const &that ) const noexcept;

	constexpr double getDistance( Vector3< T > const &to ) const noexcept;

	T x;
	T y;
	T z;
};



template< typename T >
constexpr Vector3< T >::Vector3() noexcept :
	x( 0 ),
	y( 0 ),
	z( 0 )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
constexpr Vector3< T >::Vector3( T const &x, T const &y, T const &z ) noexcept :
	x( x ),
	y( y ),
	z( z )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
constexpr Vector3< T >::Vector3( Vector2< T > const &xy, T const &z ) noexcept :
	x( xy.x ),
	y( xy.y ),
	z( z )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
template< typename U >
constexpr Vector3< T >::Vector3( U const &that ):
	x( that.x ),
	y( that.y ),
	z( that.z )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}



template< typename T >
template< typename U >
constexpr Vector3< T >::operator U() const
{
	return U( x, y, z );
}



template< typename T >
constexpr Vector3< T > Vector3< T >::operator*( Vector3< T > const &that ) const noexcept
{
	return Vector3( x * that.x, y * that.y, z * that.z );
}

template< typename T >
constexpr Vector3< T > Vector3< T >::operator/( Vector3< T > const &that ) const noexcept
{
	return Vector3( x / that.x, y / that.y, z / that.z );
}

template< typename T >
constexpr Vector3< T > Vector3< T >::operator+( Vector3< T > const &that ) const noexcept
{
	return Vector3( x + that.x, y + that.y, z + that.z );
}

template< typename T >
constexpr Vector3< T > Vector3< T >::operator-( Vector3< T > const &that ) const noexcept
{
	return Vector3( x - that.x, y - that.y, z - that.z );
}



template< typename T >
constexpr Vector3< T > &Vector3< T >::operator*=( Vector3< T > const &that ) noexcept
{
	x *= that.x;
	y *= that.y;
	z *= that.z;
	return *this;
}

template< typename T >
constexpr Vector3< T > &Vector3< T >::operator/=( Vector3< T > const &that ) noexcept
{
	x /= that.x;
	y /= that.y;
	z /= that.z;
	return *this;
}

template< typename T >
constexpr Vector3< T > &Vector3< T >::operator+=( Vector3< T > const &that ) noexcept
{
	x += that.x;
	y += that.y;
	z += that.z;
	return *this;
}

template< typename T >
constexpr Vector3< T > &Vector3< T >::operator-=( Vector3< T > const &that ) noexcept
{
	x -= that.x;
	y -= that.y;
	z -= that.z;
	return *this;
}



template< typename T >
constexpr bool Vector3< T >::operator==( Vector3< T > const &that ) const noexcept
{
	return x == that.x && y == that.y && z == that.z;
}

template< typename T >
constexpr bool Vector3< T >::operator!=( Vector3< T > const &that ) const noexcept
{
	return x != that.x || y != that.y || z != that.z;
}

template< typename T >
constexpr bool Vector3< T >::operator<=( Vector3< T > const &that ) const noexcept
{
	return *this < that || *this == that;
}

template< typename T >
constexpr bool Vector3< T >::operator>=( Vector3< T > const &that ) const noexcept
{
	return *this > that || *this == that;
}

template< typename T >
constexpr bool Vector3< T >::operator<( Vector3< T > const &that ) const noexcept
{
	return x < that.x || ( x == that.x && y < that.y ) || ( x == that.x && y == that.y && z < that.z );
}

template< typename T >
constexpr bool Vector3< T >::operator>( Vector3< T > const &that ) const noexcept
{
	return x > that.x || ( x == that.x && y > that.y ) || ( x == that.x && y == that.y && z > that.z );;
}

template< typename T >
constexpr double Vector3< T >::getDistance( Vector3< T > const &to ) const noexcept
{
	if( std::is_unsigned< T >::value )
	{
		typedef std::make_signed< T > TSigned;
		TSigned deltaX = std::abs(( TSigned )x - ( TSigned )to.x );
		TSigned deltaY = std::abs(( TSigned )y - ( TSigned )to.y );
		TSigned deltaZ = std::abs(( TSigned )z - ( TSigned )to.z );
		return std::sqrt( std::pow( deltaX, 2 ) + std::pow( deltaY, 2 ) + std::pow( deltaZ, 2 ));
	}
	else
	{
		T deltaX = std::abs( x - to.x );
		T deltaY = std::abs( y - to.y );
		T deltaZ = std::abs( z - to.z );
		return std::sqrt( std::pow( deltaX, 2 ) + std::pow( deltaY, 2 ) + std::pow( deltaZ, 2 ));
	}
}

}

}



namespace std
{

using namespace coldline::geometry;

template< typename T >
struct hash< Vector3< T > >
{
	size_t operator()( Vector3< T > const &k ) const
	{
		return ((( hash< T >()( k.x ) ^
			( hash< T >()( k.y ) << 1 ) ) >> 1 ) ^
			( hash< T >()( k.z ) << 1 ) ) >> 1;
	}
};

}
