/*
 * @file geometry/Vector3D.hpp
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

namespace geometry
{

template< typename T >
struct Vector3D;

typedef Vector3D< short > Vector3Ds;
typedef Vector3D< unsigned short > Vector3Dus;
typedef Vector3D< int > Vector3Di;
typedef Vector3D< unsigned > Vector3Du;
typedef Vector3D< long > Vector3Dl;
typedef Vector3D< unsigned long > Vector3Dul;
typedef Vector3D< long long > Vector3Dll;
typedef Vector3D< unsigned long long > Vector3Dull;
typedef Vector3D< float > Vector3Df;
typedef Vector3D< double > Vector3Dd;
typedef Vector3D< long double > Vector3Dld;

template< typename T >
struct Vector3D
{
	constexpr Vector3D() noexcept;
	constexpr Vector3D( T const &x, T const &y, T const &z ) noexcept;
	constexpr Vector3D( Vector2< T > const &xy, T const &z ) noexcept;
	template< typename U >
	constexpr Vector3D( Vector3D< U > const &that ) noexcept;
	template< typename U >
	constexpr explicit Vector3D( U const &that );

	template< typename U >
	constexpr operator Vector3D< U >() noexcept;
	template< typename U >
	constexpr explicit operator U() const;

	constexpr Vector3D< T > operator*( Vector3D< T > const &that ) const noexcept;
	constexpr Vector3D< T > operator/( Vector3D< T > const &that ) const noexcept;
	constexpr Vector3D< T > operator+( Vector3D< T > const &that ) const noexcept;
	constexpr Vector3D< T > operator-( Vector3D< T > const &that ) const noexcept;

	constexpr Vector3D< T > &operator*=( Vector3D< T > const &that ) noexcept;
	constexpr Vector3D< T > &operator/=( Vector3D< T > const &that ) noexcept;
	constexpr Vector3D< T > &operator+=( Vector3D< T > const &that ) noexcept;
	constexpr Vector3D< T > &operator-=( Vector3D< T > const &that ) noexcept;

	constexpr bool operator==( Vector3D< T > const &that ) const noexcept;
	constexpr bool operator!=( Vector3D< T > const &that ) const noexcept;
	constexpr bool operator<=( Vector3D< T > const &that ) const noexcept;
	constexpr bool operator>=( Vector3D< T > const &that ) const noexcept;
	constexpr bool operator<( Vector3D< T > const &that ) const noexcept;
	constexpr bool operator>( Vector3D< T > const &that ) const noexcept;

	constexpr double getDistance( Vector3D< T > const &to ) const noexcept;

	T x;
	T y;
	T z;
};



template< typename T >
constexpr Vector3D< T >::Vector3D() noexcept :
	x( 0 ),
	y( 0 ),
	z( 0 )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
constexpr Vector3D< T >::Vector3D( T const &x, T const &y, T const &z ) noexcept :
	x( x ),
	y( y ),
	z( z )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
constexpr Vector3D< T >::Vector3D( Vector2< T > const &xy, T const &z ) noexcept :
	x( xy.x ),
	y( xy.y ),
	z( z )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
template< typename U >
constexpr Vector3D< T >::Vector3D( Vector3D< U > const &that ) noexcept :
	x( that.x ),
	y( that.y ),
	z( that.z )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
template< typename U >
constexpr Vector3D< T >::Vector3D( U const &that ) :
	x( that.x ),
	y( that.y ),
	z( that.z )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}



template< typename T >
template< typename U >
constexpr Vector3D< T >::operator Vector3D< U >() noexcept
{
	return Vector3D< U >( x, y, z );
}

template< typename T >
template< typename U >
constexpr Vector3D< T >::operator U() const
{
	return U( x, y, z );
}



template< typename T >
constexpr Vector3D< T > Vector3D< T >::operator*( Vector3D< T > const &that ) const noexcept
{
	return Vector3D( x * that.x, y * that.y, z * that.z );
}

template< typename T >
constexpr Vector3D< T > Vector3D< T >::operator/( Vector3D< T > const &that ) const noexcept
{
	return Vector3D( x / that.x, y / that.y, z / that.z );
}

template< typename T >
constexpr Vector3D< T > Vector3D< T >::operator+( Vector3D< T > const &that ) const noexcept
{
	return Vector3D( x + that.x, y + that.y, z + that.z );
}

template< typename T >
constexpr Vector3D< T > Vector3D< T >::operator-( Vector3D< T > const &that ) const noexcept
{
	return Vector3D( x - that.x, y - that.y, z - that.z );
}



template< typename T >
constexpr Vector3D< T > &Vector3D< T >::operator*=( Vector3D< T > const &that ) noexcept
{
	x *= that.x;
	y *= that.y;
	z *= that.z;
	return *this;
}

template< typename T >
constexpr Vector3D< T > &Vector3D< T >::operator/=( Vector3D< T > const &that ) noexcept
{
	x /= that.x;
	y /= that.y;
	z /= that.z;
	return *this;
}

template< typename T >
constexpr Vector3D< T > &Vector3D< T >::operator+=( Vector3D< T > const &that ) noexcept
{
	x += that.x;
	y += that.y;
	z += that.z;
	return *this;
}

template< typename T >
constexpr Vector3D< T > &Vector3D< T >::operator-=( Vector3D< T > const &that ) noexcept
{
	x -= that.x;
	y -= that.y;
	z -= that.z;
	return *this;
}



template< typename T >
constexpr bool Vector3D< T >::operator==( Vector3D< T > const &that ) const noexcept
{
	return x == that.x && y == that.y && z == that.z;
}

template< typename T >
constexpr bool Vector3D< T >::operator!=( Vector3D< T > const &that ) const noexcept
{
	return x != that.x || y != that.y || z != that.z;
}

template< typename T >
constexpr bool Vector3D< T >::operator<=( Vector3D< T > const &that ) const noexcept
{
	return *this < that || *this == that;
}

template< typename T >
constexpr bool Vector3D< T >::operator>=( Vector3D< T > const &that ) const noexcept
{
	return *this > that || *this == that;
}

template< typename T >
constexpr bool Vector3D< T >::operator<( Vector3D< T > const &that ) const noexcept
{
	return x < that.x || ( x == that.x && y < that.y ) || ( x == that.x && y == that.y && z < that.z );
}

template< typename T >
constexpr bool Vector3D< T >::operator>( Vector3D< T > const &that ) const noexcept
{
	return x > that.x || ( x == that.x && y > that.y ) || ( x == that.x && y == that.y && z > that.z );;
}

template< typename T >
constexpr double Vector3D< T >::getDistance( Vector3D< T > const &to ) const noexcept
{
	if( std::is_unsigned< T >::value )
	{
		typedef std::make_signed< T > TSigned;
		TSigned deltaX = std::abs( static_cast< TSigned >( x ) - static_cast< TSigned >( to.x ));
		TSigned deltaY = std::abs( static_cast< TSigned >( y ) - static_cast< TSigned >( to.y ));
		TSigned deltaZ = std::abs( static_cast< TSigned >( z ) - static_cast< TSigned >( to.z ));
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
struct hash< Vector3D< T > >
{
	size_t operator()( Vector3D< T > const &k ) const
	{
		return ((( hash< T >()( k.x ) ^
			( hash< T >()( k.y ) << 1 ) ) >> 1 ) ^
			( hash< T >()( k.z ) << 1 ) ) >> 1;
	}
};
