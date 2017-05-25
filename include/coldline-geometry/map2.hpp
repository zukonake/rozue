/*
 * @file coldline-geometry/map2.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <stdexcept>
#include <utility>
//
#include <coldline-geometry/typedef.hpp>
#include <coldline-geometry/vector2.hpp>

namespace coldline::geometry
{

template< typename U, Dimension width, Dimension height >
class Map2
{
public:
	Map2() = default;
	Map2( U const &fill );
	Map2( Map2< U, width, height > const &that );
	Map2( Map2< U, width, height > &&that );

	~Map2() = default;

	Map2 &operator=( U const &fill );
	Map2 &operator=( Map2< U, width, height > const &that );
	Map2 &operator=( Map2< U, width, height > &&that );

	U &operator[]( Vector2u const &index ) noexcept;
	U const &operator[]( Vector2u const &index ) const noexcept;

	U &at( Vector2u const &index );
	U const &at( Vector2u const &index ) const;
private:
	std::array< std::array< U, width >, width > value;
};

template< typename U, Dimension width, Dimension height >
Map2< U, width, height >::Map2( U const &fill )
{
	for( UnsignedInt iY = 0; iY < height; iY++ )
	{
		for( UnsignedInt iX = 0; iX < height; iX++ )
		{
			value[ iY ][ iX ] = fill;
		}
	}
}

template< typename U, Dimension width, Dimension height >
Map2< U, width, height >::Map2( Map2< U, width, height > const &that )
{
	for( UnsignedInt iY = 0; iY < height; iY++ )
	{
		for( UnsignedInt iX = 0; iX < height; iX++ )
		{
			value[ iY ][ iX ] = that.value[ iY ][ iX ];
		}
	}
}

template< typename U, Dimension width, Dimension height >
Map2< U, width, height >::Map2( Map2< U, width, height > &&that ) :
	value( std::move( that.value ))
{

}

template< typename U, Dimension width, Dimension height >
Map2< U, width, height > &Map2< U, width, height >::operator=( U const &fill )
{
	for( UnsignedInt iY = 0; iY < height; iY++ )
	{
		for( UnsignedInt iX = 0; iX < height; iX++ )
		{
			value[ iY ][ iX ] = fill;
		}
	}
	return *this;
}

template< typename U, Dimension width, Dimension height >
Map2< U, width, height > &Map2< U, width, height >::operator=( Map2< U, width, height > const &that )
{
	for( UnsignedInt iY = 0; iY < height; iY++ )
	{
		for( UnsignedInt iX = 0; iX < height; iX++ )
		{
			value[ iY ][ iX ] = that.value[ iY ][ iX ];
		}
	}
	return *this;
}

template< typename U, Dimension width, Dimension height >
Map2< U, width, height > &Map2< U, width, height >::operator=( Map2< U, width, height > &&that )
{
	value.swap( that.value );
	return *this;
}

template< typename U, Dimension width, Dimension height >
U &Map2< U, width, height >::operator[]( Vector2u const &index ) noexcept
{
	return value[ index.y ][ index.x ];
}

template< typename U, Dimension width, Dimension height >
U const &Map2< U, width, height >::operator[]( Vector2u const &index ) const noexcept
{
	return value[ index.y ][ index.x ];
}

template< typename U, Dimension width, Dimension height >
U &Map2< U, width, height >::at( Vector2u const &index )
{
	if( index.x < 0 || index.x >= width || index.y < 0 || index.y >= height )
	{
		throw std::out_of_range();
	}
	return value[ index.y ][ index.x ];
}

template< typename U, Dimension width, Dimension height >
U const &Map2< U, width, height >::at( Vector2u const &index ) const
{
	if( index.x < 0 || index.x >= width || index.y < 0 || index.y >= height )
	{
		throw std::out_of_range();
	}
	return value[ index.y ][ index.x ];
}

}
