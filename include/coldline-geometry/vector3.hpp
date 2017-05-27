/*
 * @file coldline-geometry/vector3.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <cstddef>
#include <functional>
//
#include <coldline-geometry/typedef.hpp>

namespace coldline::geometry
{

template< typename T >
struct Vector3;

typedef Vector3< Int > Vector3i;
typedef Vector3< UnsignedInt > Vector3u;
typedef Vector3< float > Vector3f;
typedef Vector3< double > Vector3d;

template< typename T >
struct Vector3
{
	constexpr Vector3() = default;
	constexpr Vector3( T const &x, T const &y, T const &z ) noexcept;
	template< typename U >
	constexpr explicit Vector3( U const &that ) noexcept;

	~Vector3() = default;

	template< typename U >
	constexpr operator U() const noexcept;

	constexpr Vector3< T > operator*( Vector3< T > const &that ) const noexcept;
	constexpr Vector3< T > operator/( Vector3< T > const &that ) const noexcept;
	constexpr Vector3< T > operator%( Vector3< T > const &that ) const noexcept;
	constexpr Vector3< T > operator+( Vector3< T > const &that ) const noexcept;
	constexpr Vector3< T > operator-( Vector3< T > const &that ) const noexcept;

	constexpr Vector3< T > &operator=( Vector3< T > const &that ) noexcept;
	constexpr Vector3< T > &operator*=( Vector3< T > const &that ) noexcept;
	constexpr Vector3< T > &operator/=( Vector3< T > const &that ) noexcept;
	constexpr Vector3< T > &operator%=( Vector3< T > const &that ) noexcept;
	constexpr Vector3< T > &operator+=( Vector3< T > const &that ) noexcept;
	constexpr Vector3< T > &operator-=( Vector3< T > const &that ) noexcept;

	constexpr bool operator==( Vector3< T > const &that ) const noexcept;
	constexpr bool operator!=( Vector3< T > const &that ) const noexcept;
	constexpr bool operator<=( Vector3< T > const &that ) const noexcept;
	constexpr bool operator>=( Vector3< T > const &that ) const noexcept;
	constexpr bool operator<( Vector3< T > const &that ) const noexcept;
	constexpr bool operator>( Vector3< T > const &that ) const noexcept;

	T x;
	T y;
	T z;
};

template< typename T >
struct Vector3Hasher
{
	std::size_t operator()( Vector3< T > const &k ) const;
};



template< typename T >
constexpr Vector3< T >::Vector3( T const &x, T const &y, T const &z ) noexcept :
	x( x ),
	y( y ),
	z( z )
{

}

template< typename T >
template< typename U >
constexpr Vector3< T >::Vector3( U const &that ) noexcept :
	x( that.x ),
	y( that.y ),
	z( that.z )
{

}



template< typename T >
template< typename U >
constexpr Vector3< T >::operator U() const noexcept
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
constexpr Vector3< T > Vector3< T >::operator%( Vector3< T > const &that ) const noexcept
{
	return Vector3( x % that.x, y % that.y, z % that.z );
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
constexpr Vector3< T > &Vector3< T >::operator=( Vector3< T > const &that ) noexcept
{
	x = that.x;
	y = that.y;
	z = that.z;
	return *this;
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
constexpr Vector3< T > &Vector3< T >::operator%=( Vector3< T > const &that ) noexcept
{
	x %= that.x;
	y %= that.y;
	z %= that.z;
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
std::size_t Vector3Hasher< T >::operator()( Vector3< T > const &k ) const
{
	return ((( std::hash< T >()( k.x ) ^ //Not sure if this even works
		( std::hash< T >()( k.y ) << 1 ) ) >> 1 ) ^
		( std::hash< T >()( k.z ) << 1 ) ) >> 1;
}

}
