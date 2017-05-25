/*
 * @file coldline-geometry/map3.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <stdexcept>
//
#include <coldline-geometry/typedef.hpp>
#include <coldline-geometry/vector3.hpp>

namespace coldline::geometry
{

template< typename U, Dimension width, Dimension height, Dimension depth >
class Map3
{
public:
	Map3() = default;
	Map3( U const &fill );
	Map3( Map3< U, width, height, depth > const &that );
	Map3( Map3< U, width, height, depth > &&that );

	~Map3() = default;

	Map3 &operator=( U const &fill );
	Map3 &operator=( Map3< U, width, height, depth > const &that );
	Map3 &operator=( Map3< U, width, height, depth > &&that );

	U &operator[]( Vector3u const &index ) noexcept;
	U const &operator[]( Vector3u const &index ) const noexcept;

	U &at( Vector3u const &index );
	U const &at( Vector3u const &index ) const;
private:
	std::array< std::array< std::array< U, width >, width >, depth > value;
};

template< typename U, Dimension width, Dimension height, Dimension depth >
Map3< U, width, height, depth >::Map3( U const &fill )
{
	for( UnsignedInt iZ = 0; iZ < depth; iZ++ )
	{
		for( UnsignedInt iY = 0; iY < height; iY++ )
		{
			for( UnsignedInt iX = 0; iX < height; iX++ )
			{
				value[ iZ ][ iY ][ iX ] = fill;
			}
		}
	}
}

template< typename U, Dimension width, Dimension height, Dimension depth >
Map3< U, width, height, depth >::Map3( Map3< U, width, height, depth > const &that )
{
	for( UnsignedInt iZ = 0; iZ < depth; iZ++ )
	{
		for( UnsignedInt iY = 0; iY < height; iY++ )
		{
			for( UnsignedInt iX = 0; iX < height; iX++ )
			{
				value[ iZ ][ iY ][ iX ] = that.value[ iZ ][ iY ][ iX ];
			}
		}
	}
}

template< typename U, Dimension width, Dimension height, Dimension depth >
Map3< U, width, height, depth >::Map3( Map3< U, width, height, depth > &&that ) :
	value( std::move( that.value ))
{

}

template< typename U, Dimension width, Dimension height, Dimension depth >
Map3< U, width, height, depth > &Map3< U, width, height, depth >::operator=( U const &fill )
{
	for( UnsignedInt iZ = 0; iZ < depth; iZ++ )
	{
		for( UnsignedInt iY = 0; iY < height; iY++ )
		{
			for( UnsignedInt iX = 0; iX < height; iX++ )
			{
				value[ iZ ][ iY ][ iX ] = fill;
			}
		}
	}
	return *this;
}

template< typename U, Dimension width, Dimension height, Dimension depth >
Map3< U, width, height, depth > &Map3< U, width, height, depth >::operator=( Map3< U, width, height, depth > const &that )
{
	for( UnsignedInt iZ = 0; iZ < depth; iZ++ )
	{
		for( UnsignedInt iY = 0; iY < height; iY++ )
		{
			for( UnsignedInt iX = 0; iX < height; iX++ )
			{
				value[ iZ ][ iY ][ iX ] = that.value[ iZ ][ iY ][ iX ];
			}
		}
	}
	return *this;
}

template< typename U, Dimension width, Dimension height, Dimension depth >
Map3< U, width, height, depth > &Map3< U, width, height, depth >::operator=( Map3< U, width, height, depth > &&that )
{
	value.swap( that.value );
	return *this;
}

template< typename U, Dimension width, Dimension height, Dimension depth >
U &Map3< U, width, height, depth >::operator[]( Vector3u const &index ) noexcept
{
	return value[ index.z ][ index.y ][ index.x ];
}

template< typename U, Dimension width, Dimension height, Dimension depth >
U const &Map3< U, width, height, depth >::operator[]( Vector3u const &index ) const noexcept
{
	return value[ index.z ][ index.y ][ index.x ];
}

template< typename U, Dimension width, Dimension height, Dimension depth >
U &Map3< U, width, height, depth >::at( Vector3u const &index )
{
	if( index.x < 0 || index.x >= width || index.y < 0 || index.y >= height || index.z < 0 || index.z >= depth )
	{
		throw std::out_of_range();
	}
	return value[ index.z ][ index.y ][ index.x ];
}

template< typename U, Dimension width, Dimension height, Dimension depth >
U const &Map3< U, width, height, depth >::at( Vector3u const &index ) const
{
	if( index.x < 0 || index.x >= width || index.y < 0 || index.y >= height || index.z < 0 || index.z >= depth )
	{
		throw std::out_of_range();
	}
	return value[ index.z ][ index.y ][ index.x ];
}

}
