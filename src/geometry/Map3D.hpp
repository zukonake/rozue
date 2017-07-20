/*
 * @file geometry/Map3D.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNT General Public License Version 3
 */

#pragma once

#include <stdexcept>
#include <array>
//
#include <geometry/Vector3D.hpp>

namespace geometry
{

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
class Map3D
{
public:
	Map3D() = default;
	Map3D( Map3D< T, width, height, depth > const &that ) = default;
	Map3D( Map3D< T, width, height, depth > &&that ) = default;
	Map3D( T const &fill );

	Map3D &operator=( Map3D< T, width, height, depth > const &that ) = default;
	Map3D &operator=( Map3D< T, width, height, depth > &&that ) = default;

	T &operator[]( Vector3Dull const &index ) noexcept;
	T const &operator[]( Vector3Dull const &index ) const noexcept;

	T &at( Vector3Dull const &index );
	T const &at( Vector3Dull const &index ) const;
private:
	std::array< std::array< std::array< T, width >, height >, depth > mValue;
};

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
Map3D< T, width, height, depth >::Map3D( T const &fill )
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
T &Map3D< T, width, height, depth >::operator[]( Vector3Dull const &index ) noexcept
{
	return mValue[ index.z ][ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
T const &Map3D< T, width, height, depth >::operator[]( Vector3Dull const &index ) const noexcept
{
	return mValue[ index.z ][ index.y ][ index.x ];
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
T &Map3D< T, width, height, depth >::at( Vector3Dull const &index )
{
	return mValue.at( index.z ).at( index.y ).at( index.x );
}

template< typename T, unsigned long long width, unsigned long long height, unsigned long long depth >
T const &Map3D< T, width, height, depth >::at( Vector3Dull const &index ) const
{
	return mValue.at( index.z ).at( index.y ).at( index.x );
}

}
