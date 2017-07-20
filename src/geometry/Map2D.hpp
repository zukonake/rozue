/*
 * @file geometry/Map2D.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNT General Public License Version 3
 */

#pragma once

#include <stdexcept>
#include <array>
//
#include <geometry/Vector2D.hpp>

namespace geometry
{

template< typename T, unsigned long long width, unsigned long long height >
class Map2D
{
public:
	Map2D() = default;
	Map2D( Map2D< T, width, height > const &that ) = default;
	Map2D( Map2D< T, width, height > &&that ) = default;
	Map2D( T const &fill );

	Map2D &operator=( Map2D< T, width, height > const &that ) = default;
	Map2D &operator=( Map2D< T, width, height > &&that ) = default;

	T &operator[]( Vector2Dull const &index );
	T const &operator[]( Vector2Dull const &index ) const;

	T &at( Vector2Dull const &index );
	T const &at( Vector2Dull const &index ) const;
private:
	std::array< std::array< T, width >, height > mValue;
};

template< typename T, unsigned long long width, unsigned long long height >
Map2D< T, width, height >::Map2D( T const &fill )
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
T &Map2D< T, width, height >::operator[]( Vector2Dull const &index )
{
	return mValue[ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height >
T const &Map2D< T, width, height >::operator[]( Vector2Dull const &index ) const
{
	return mValue[ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height >
T &Map2D< T, width, height >::at( Vector2Dull const &index )
{
	return mValue[ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height >
T const &Map2D< T, width, height >::at( Vector2Dull const &index ) const
{
	return mValue[ index.y ][ index.x ];
}

}
