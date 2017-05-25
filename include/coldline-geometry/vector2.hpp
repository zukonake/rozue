/*
 * @file coldline-geometry/vector2.hpp
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
struct Vector2;

typedef Vector2< Int > Vector2i;
typedef Vector2< UnsignedInt > Vector2u;
typedef Vector2< float > Vector2f;
typedef Vector2< double > Vector2d;

template< typename T >
struct Vector2
{
	constexpr Vector2() = default;
	constexpr Vector2( T const &x, T const &y ) noexcept;
	template< typename U >
	constexpr Vector2( U const &that ) noexcept;

	~Vector2() = default;

	template< typename U >
	constexpr operator U() const noexcept;

	constexpr Vector2< T > operator*( Vector2< T > const &that ) const noexcept;
	constexpr Vector2< T > operator/( Vector2< T > const &that ) const noexcept;
	constexpr Vector2< T > operator%( Vector2< T > const &that ) const noexcept;
	constexpr Vector2< T > operator+( Vector2< T > const &that ) const noexcept;
	constexpr Vector2< T > operator-( Vector2< T > const &that ) const noexcept;

	constexpr Vector2< T > &operator=( Vector2< T > const &that ) noexcept;
	constexpr Vector2< T > &operator*=( Vector2< T > const &that ) noexcept;
	constexpr Vector2< T > &operator/=( Vector2< T > const &that ) noexcept;
	constexpr Vector2< T > &operator%=( Vector2< T > const &that ) noexcept;
	constexpr Vector2< T > &operator+=( Vector2< T > const &that ) noexcept;
	constexpr Vector2< T > &operator-=( Vector2< T > const &that ) noexcept;

	constexpr bool operator==( Vector2< T > const &that ) const noexcept;
	constexpr bool operator!=( Vector2< T > const &that ) const noexcept;
	constexpr bool operator<=( Vector2< T > const &that ) const noexcept;
	constexpr bool operator>=( Vector2< T > const &that ) const noexcept;
	constexpr bool operator<( Vector2< T > const &that ) const noexcept;
	constexpr bool operator>( Vector2< T > const &that ) const noexcept;

	T x;
	T y;
};

template< typename T >
struct Vector2Hasher
{
	std::size_t operator()( Vector2< T > const &k ) const;
};

template< typename T >
constexpr Vector2< T >::Vector2( T const &x, T const &y ) noexcept :
	x( x ),
	y( y )
{

}

template< typename T >
template< typename U >
constexpr Vector2< T >::Vector2( U const &that ) noexcept :
	x( that.x ),
	y( that.y )
{

}



template< typename T >
template< typename U >
constexpr Vector2< T >::operator U() const noexcept
{
	return U( x, y );
}



template< typename T >
constexpr Vector2< T > Vector2< T >::operator*( Vector2< T > const &that ) const noexcept
{
	return Vector2( x * that.x, y * that.y );
}

template< typename T >
constexpr Vector2< T > Vector2< T >::operator/( Vector2< T > const &that ) const noexcept
{
	return Vector2( x / that.x, y / that.y );
}

template< typename T >
constexpr Vector2< T > Vector2< T >::operator%( Vector2< T > const &that ) const noexcept
{
	return Vector2( x % that.x, y % that.y );
}

template< typename T >
constexpr Vector2< T > Vector2< T >::operator+( Vector2< T > const &that ) const noexcept
{
	return Vector2( x + that.x, y + that.y );
}

template< typename T >
constexpr Vector2< T > Vector2< T >::operator-( Vector2< T > const &that ) const noexcept
{
	return Vector2( x - that.x, y - that.y );
}



template< typename T >
constexpr Vector2< T > &Vector2< T >::operator=( Vector2< T > const &that ) noexcept
{
	x = that.x;
	y = that.y;
	return *this;
}

template< typename T >
constexpr Vector2< T > &Vector2< T >::operator*=( Vector2< T > const &that ) noexcept
{
	x *= that.x;
	y *= that.y;
	return *this;
}

template< typename T >
constexpr Vector2< T > &Vector2< T >::operator/=( Vector2< T > const &that ) noexcept
{
	x /= that.x;
	y /= that.y;
	return *this;
}

template< typename T >
constexpr Vector2< T > &Vector2< T >::operator%=( Vector2< T > const &that ) noexcept
{
	x %= that.x;
	y %= that.y;
	return *this;
}

template< typename T >
constexpr Vector2< T > &Vector2< T >::operator+=( Vector2< T > const &that ) noexcept
{
	x += that.x;
	y += that.y;
	return *this;
}

template< typename T >
constexpr Vector2< T > &Vector2< T >::operator-=( Vector2< T > const &that ) noexcept
{
	x -= that.x;
	y -= that.y;
	return *this;
}



template< typename T >
constexpr bool Vector2< T >::operator==( Vector2< T > const &that ) const noexcept
{
	return x == that.x && y == that.y;
}

template< typename T >
constexpr bool Vector2< T >::operator!=( Vector2< T > const &that ) const noexcept
{
	return x != that.x || y != that.y;
}

template< typename T >
constexpr bool Vector2< T >::operator<=( Vector2< T > const &that ) const noexcept
{
	return *this < that || *this == that;
}

template< typename T >
constexpr bool Vector2< T >::operator>=( Vector2< T > const &that ) const noexcept
{
	return *this > that || *this == that;
}

template< typename T >
constexpr bool Vector2< T >::operator<( Vector2< T > const &that ) const noexcept
{
	return x < that.x || ( x == that.x && y < that.y );
}

template< typename T >
constexpr bool Vector2< T >::operator>( Vector2< T > const &that ) const noexcept
{
	return x > that.x || ( x == that.x && y > that.y );
}



template< typename T >
std::size_t Vector2Hasher< T >::operator()( Vector2< T > const &k ) const
{
	return ( ( std::hash< T >()( k.x ) xor
	( std::hash< T >()( k.y ) << 1 ) ) >> 1 );
}

}
