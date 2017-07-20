/*
 * @file geometry/Vector2D.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <type_traits>
#include <functional>

namespace geometry
{

template< typename T >
struct Vector2D;

typedef Vector2D< short > Vector2Ds;
typedef Vector2D< unsigned short > Vector2Dus;
typedef Vector2D< int > Vector2Di;
typedef Vector2D< unsigned > Vector2Du;
typedef Vector2D< long > Vector2Dl;
typedef Vector2D< unsigned long > Vector2Dul;
typedef Vector2D< long long > Vector2Dll;
typedef Vector2D< unsigned long long > Vector2Dull;
typedef Vector2D< float > Vector2Df;
typedef Vector2D< double > Vector2Dd;
typedef Vector2D< long double > Vector2Dld;

template< typename T >
struct Vector2D
{
	constexpr Vector2D() noexcept;
	constexpr Vector2D( T const &x, T const &y ) noexcept;
	template< typename U >
	constexpr Vector2D( Vector2D< U > const &that ) noexcept;
	template< typename U >
	constexpr explicit Vector2D( U const &that );

	template< typename U >
	constexpr operator Vector2D< U >() const noexcept;
	template< typename U >
	constexpr explicit operator U() const;

	constexpr Vector2D< T > operator*( Vector2D< T > const &that ) const noexcept;
	constexpr Vector2D< T > operator/( Vector2D< T > const &that ) const noexcept;
	constexpr Vector2D< T > operator+( Vector2D< T > const &that ) const noexcept;
	constexpr Vector2D< T > operator-( Vector2D< T > const &that ) const noexcept;

	constexpr Vector2D< T > &operator*=( Vector2D< T > const &that ) noexcept;
	constexpr Vector2D< T > &operator/=( Vector2D< T > const &that ) noexcept;
	constexpr Vector2D< T > &operator+=( Vector2D< T > const &that ) noexcept;
	constexpr Vector2D< T > &operator-=( Vector2D< T > const &that ) noexcept;

	constexpr bool operator==( Vector2D< T > const &that ) const noexcept;
	constexpr bool operator!=( Vector2D< T > const &that ) const noexcept;
	constexpr bool operator<=( Vector2D< T > const &that ) const noexcept;
	constexpr bool operator>=( Vector2D< T > const &that ) const noexcept;
	constexpr bool operator<( Vector2D< T > const &that ) const noexcept;
	constexpr bool operator>( Vector2D< T > const &that ) const noexcept;

	constexpr double getDistance( Vector2D< T > const &to ) const noexcept;

	T x;
	T y;
};



template< typename T >
constexpr Vector2D< T >::Vector2D() noexcept :
	x( 0 ),
	y( 0 )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
constexpr Vector2D< T >::Vector2D( T const &x, T const &y ) noexcept :
	x( x ),
	y( y )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}

template< typename T >
template< typename U >
constexpr Vector2D< T >::Vector2D( Vector2D< U > const &that ) noexcept :
	x( that.x ),
	y( that.y )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
	static_assert( std::is_arithmetic< U >::value, "Vector parameters mus be arithmetic" );
	
}

template< typename T >
template< typename U >
constexpr Vector2D< T >::Vector2D( U const &that ) :
	x( that.x ),
	y( that.y )
{
	static_assert( std::is_arithmetic< T >::value, "Vector parameters mus be arithmetic" );
}



template< typename T >
template< typename U >
constexpr Vector2D< T >::operator Vector2D< U >() const noexcept
{
	return Vector2D< U >( x, y );
}

template< typename T >
template< typename U >
constexpr Vector2D< T >::operator U() const
{
	return U( x, y );
}



template< typename T >
constexpr Vector2D< T > Vector2D< T >::operator*( Vector2D< T > const &that ) const noexcept
{
	return Vector2D( x * that.x, y * that.y );
}

template< typename T >
constexpr Vector2D< T > Vector2D< T >::operator/( Vector2D< T > const &that ) const noexcept
{
	return Vector2D( x / that.x, y / that.y );
}

template< typename T >
constexpr Vector2D< T > Vector2D< T >::operator+( Vector2D< T > const &that ) const noexcept
{
	return Vector2D( x + that.x, y + that.y );
}

template< typename T >
constexpr Vector2D< T > Vector2D< T >::operator-( Vector2D< T > const &that ) const noexcept
{
	return Vector2D( x - that.x, y - that.y );
}



template< typename T >
constexpr Vector2D< T > &Vector2D< T >::operator*=( Vector2D< T > const &that ) noexcept
{
	x *= that.x;
	y *= that.y;
	return *this;
}

template< typename T >
constexpr Vector2D< T > &Vector2D< T >::operator/=( Vector2D< T > const &that ) noexcept
{
	x /= that.x;
	y /= that.y;
	return *this;
}

template< typename T >
constexpr Vector2D< T > &Vector2D< T >::operator+=( Vector2D< T > const &that ) noexcept
{
	x += that.x;
	y += that.y;
	return *this;
}

template< typename T >
constexpr Vector2D< T > &Vector2D< T >::operator-=( Vector2D< T > const &that ) noexcept
{
	x -= that.x;
	y -= that.y;
	return *this;
}



template< typename T >
constexpr bool Vector2D< T >::operator==( Vector2D< T > const &that ) const noexcept
{
	return x == that.x && y == that.y;
}

template< typename T >
constexpr bool Vector2D< T >::operator!=( Vector2D< T > const &that ) const noexcept
{
	return x != that.x || y != that.y;
}

template< typename T >
constexpr bool Vector2D< T >::operator<=( Vector2D< T > const &that ) const noexcept
{
	return *this < that || *this == that;
}

template< typename T >
constexpr bool Vector2D< T >::operator>=( Vector2D< T > const &that ) const noexcept
{
	return *this > that || *this == that;
}

template< typename T >
constexpr bool Vector2D< T >::operator<( Vector2D< T > const &that ) const noexcept
{
	return x < that.x || ( x == that.x && y < that.y );
}

template< typename T >
constexpr bool Vector2D< T >::operator>( Vector2D< T > const &that ) const noexcept
{
	return x > that.x || ( x == that.x && y > that.y );
}

template< typename T >
constexpr double Vector2D< T >::getDistance( Vector2D< T > const &to ) const noexcept
{
	if( std::is_unsigned< T >::value )
	{
		typedef std::make_signed< T > TSigned;
		TSigned deltaX = std::abs( static_cast< TSigned >( x ) - static_cast< TSigned >( to.x ));
		TSigned deltaY = std::abs( static_cast< TSigned >( y ) - static_cast< TSigned >( to.y ));
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
struct hash< Vector2D< T > >
{
	size_t operator()( Vector2D< T > const &k ) const
	{
		return ( ( hash< T >()( k.x ) ^
			( hash< T >()( k.y ) << 1 ) ) >> 1 );
	}
};
