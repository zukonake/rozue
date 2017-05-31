/*
 * @file geometry/map2.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNT General Public License Version 3
 */

#pragma once

#include <stdexcept>
#include <array>
//
#include <geometry/vector2.hpp>

namespace coldline
{

namespace geometry
{

template< typename T, unsigned long long width, unsigned long long height >
class Map2
{
public:
	Map2() = default;
	Map2( T const &fill );
	Map2( Map2< T, width, height > const &that );
	Map2( Map2< T, width, height > &&that );

	~Map2() = default;

	Map2 &operator=( Map2< T, width, height > const &that );
	Map2 &operator=( Map2< T, width, height > &&that );

	T &operator[]( Vector2ull const &index );
	T const &operator[]( Vector2ull const &index ) const;

	T &at( Vector2ull const &index );
	T const &at( Vector2ull const &index ) const;
private:
	std::array< std::array< T, width >, height > mValue;
};

template< typename T, unsigned long long width, unsigned long long height >
Map2< T, width, height >::Map2( T const &fill )
{
	for( unsigned long long iY = 0; iY < height; iY++ )
	{
		for( unsigned long long iX = 0; iX < width; iX++ )
		{
			mValue[ iY ].push_back( fill );
		}
	}
}

template< typename T, unsigned long long width, unsigned long long height >
Map2< T, width, height >::Map2( Map2< T, width, height > const &that )
{
	mValue = that.mValue;
}

template< typename T, unsigned long long width, unsigned long long height >
Map2< T, width, height >::Map2( Map2< T, width, height > &&that ) :
	mValue( std::move( that.mValue ))
{

}

template< typename T, unsigned long long width, unsigned long long height >
Map2< T, width, height > &Map2< T, width, height >::operator=( T const &fill )
{
	for( unsigned long long iY = 0; iY < height; iY++ )
	{
		for( unsigned long long iX = 0; iX < width; iX++ )
		{
			mValue[ iY ][ iX ] = fill;
		}
	}
	return *this;
}

template< typename T, unsigned long long width, unsigned long long height >
Map2< T, width, height > &Map2< T, width, height >::operator=( Map2< T, width, height > const &that )
{
	mValue = that.mValue;
	return *this;
}

template< typename T, unsigned long long width, unsigned long long height >
Map2< T, width, height > &Map2< T, width, height >::operator=( Map2< T, width, height > &&that )
{
	mValue.swap( that.mValue );
	return *this;
}

template< typename T, unsigned long long width, unsigned long long height >
T &Map2< T, width, height >::operator[]( Vector2ull const &index )
{
	return mValue[ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height >
T const &Map2< T, width, height >::operator[]( Vector2ull const &index ) const
{
	return mValue[ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height >
T &Map2< T, width, height >::at( Vector2ull const &index )
{
	return mValue[ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height >
T const &Map2< T, width, height >::at( Vector2ull const &index ) const
{
	return mValue[ index.y ][ index.x ];
}

}

}
