/*
 * @file geometry/vector2.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <type_traits>
#include <functional>

namespace coldline
{

namespace geometry
{

template< typename T >
struct Vector2;

typedef Vector2< short > Vector2s;
typedef Vector2< unsigned short > Vector2us;
typedef Vector2< int > Vector2i;
typedef Vector2< unsigned > Vector2u;
typedef Vector2< long > Vector2l;
typedef Vector2< unsigned long > Vector2ul;
typedef Vector2< long long > Vector2ll;
typedef Vector2< unsigned long long > Vector2ull;
typedef Vector2< float > Vector2f;
typedef Vector2< double > Vector2d;
typedef Vector2< long double > Vector2ld;

template< typename T >
struct Vector2
{
	constexpr Vector2() noexcept;
	constexpr Vector2( T const &x, T const &y ) noexcept;
	template< typename U >
	constexpr Vector2( Vector2< U > const &that ) noexcept;
	template< typename U >
	constexpr explicit Vector2( U const &that );

	template< typename U >
	constexpr operator Vector2< U >() const noexcept;
	template< typename U >
	constexpr explicit operator U() const;

	constexpr Vector2< T > operator*( Vector2< T > const &that ) const noexcept;
	constexpr Vector2< T > operator/( Vector2< T > const &that ) const noexcept;
	constexpr Vector2< T > operator+( Vector2< T > const &that ) const noexcept;
	constexpr Vector2< T > operator-( Vector2< T > const &that ) const noexcept;

	constexpr Vector2< T > &operator*=( Vector2< T > const &that ) noexcept;
	constexpr Vector2< T > &operator/=( Vector2< T > const &that ) noexcept;
	constexpr Vector2< T > &operator+=( Vector2< T > const &that ) noexcept;
	constexpr Vector2< T > &operator-=( Vector2< T > const &that ) noexcept;

	constexpr bool operator==( Vector2< T > const &that ) const noexcept;
	constexpr bool operator!=( Vector2< T > const &that ) const noexcept;
	constexpr bool operator<=( Vector2< T > const &that ) const noexcept;
	constexpr bool operator>=( Vector2< T > const &that ) const noexcept;
	constexpr bool operator<( Vector2< T > const &that ) const noexcept;
	constexpr bool operator>( Vector2< T > const &that ) const noexcept;

	constexpr double getDistance( Vector2< T > const &to ) const noexcept;

	T x;
	T y;
};



template< typename T >
constexpr Vector2< T >::Vector2() noexcept :
	x( 0 ),
	y( 0 )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
constexpr Vector2< T >::Vector2( T const &x, T const &y ) noexcept :
	x( x ),
	y( y )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
template< typename U >
constexpr Vector2< T >::Vector2( Vector2< U > const &that ) noexcept :
	x(( T )that.x ),
	y(( T )that.y )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
	static_assert( std::is_arithmetic< U >::value, "Vector parameters mus be arithmetic" );
	
}

template< typename T >
template< typename U >
constexpr Vector2< T >::Vector2( U const &that ) :
	x(( T )that.x ),
	y(( T )that.y )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}



template< typename T >
template< typename U >
constexpr Vector2< T >::operator Vector2< U >() const noexcept
{
	return Vector2< U >( x, y );
}

template< typename T >
template< typename U >
constexpr Vector2< T >::operator U() const
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
constexpr double Vector2< T >::getDistance( Vector2< T > const &to ) const noexcept
{
	if( std::is_unsigned< T >::value )
	{
		typedef std::make_signed< T > TSigned;
		TSigned deltaX = std::abs(( TSigned )x - ( TSigned )to.x );
		TSigned deltaY = std::abs(( TSigned )y - ( TSigned )to.y );
		return std::sqrt( std::pow( deltaX, 2 ) + std::pow( deltaY, 2 ));
	}
	else
	{
		T deltaX = std::abs( x - to.x );
		T deltaY = std::abs( y - to.y );
		return std::sqrt( std::pow( deltaX, 2 ) + std::pow( deltaY, 2 ));
	}
}

}

}



namespace std
{

using namespace coldline::geometry;

template< typename T >
struct hash< Vector2< T > >
{
	size_t operator()( Vector2< T > const &k ) const
	{
		return ( ( hash< T >()( k.x ) ^
			( hash< T >()( k.y ) << 1 ) ) >> 1 );
	}
};

}
