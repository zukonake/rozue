/*
 * @file geometry/map3.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNT General Public License Version 3
 */

#pragma once

#include <stdexcept>
#include <array>
//
#include <geometry/vector3.hpp>

namespace coldline
{

namespace geometry
{

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
class Map3
{
public:
	Map3() = default;
	Map3( T const &fill );
	Map3( Map3< T, width, height, depth > const &that );
	Map3( Map3< T, width, height, depth > &&that );

	~Map3() = default;

	Map3 &operator=( T const &fill );
	Map3 &operator=( Map3< T, width, height, depth > const &that );
	Map3 &operator=( Map3< T, width, height, depth > &&that );

	T &operator[]( Vector3ull const &index );
	T const &operator[]( Vector3ull const &index ) const;

	T &at( Vector3ull const &index );
	T const &at( Vector3ull const &index ) const;
private:
	std::array< std::array< std::array< T, width >, height >, depth > mValue;
};

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
Map3< T, width, height, depth >::Map3( T const &fill )
{
	for( unsigned long long iZ = 0; iZ < depth; iZ++ )
	{
		for( unsigned long long iY = 0; iY < height; iY++ )
		{
			for( unsigned long long iX = 0; iX < width; iX++ )
			{
				mValue[ iZ ][ iY ][ iX ] = fill;
			}
		}
	}
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
Map3< T, width, height, depth >::Map3( Map3< T, width, height, depth > const &that )
{
	mValue = that.mValue;
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
Map3< T, width, height, depth >::Map3( Map3< T, width, height, depth > &&that ) :
	mValue( std::move( that.mValue ))
{

}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
Map3< T, width, height, depth > &Map3< T, width, height, depth >::operator=( T const &fill )
{
	for( unsigned long long iZ = 0; iZ < depth; iZ++ )
	{
		for( unsigned long long iY = 0; iY < height; iY++ )
		{
			for( unsigned long long iX = 0; iX < width; iX++ )
			{
				mValue[ iZ ][ iY ][ iX ] = fill;
			}
		}
	}
	return *this;
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
Map3< T, width, height, depth > &Map3< T, width, height, depth >::operator=( Map3< T, width, height, depth > const &that )
{
	mValue = that.mValue;
	return *this;
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
Map3< T, width, height, depth > &Map3< T, width, height, depth >::operator=( Map3< T, width, height, depth > &&that )
{
	mValue.swap( that.mValue );
	return *this;
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
T &Map3< T, width, height, depth >::operator[]( Vector3ull const &index )
{
	return mValue[ index.z ][ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
T const &Map3< T, width, height, depth >::operator[]( Vector3ull const &index ) const
{
	return mValue[ index.z ][ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
T &Map3< T, width, height, depth >::at( Vector3ull const &index )
{
	return mValue[ index.z ][ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
T const &Map3< T, width, height, depth >::at( Vector3ull const &index ) const
{
	return mValue[ index.z ][ index.y ][ index.x ];
}

}

}
