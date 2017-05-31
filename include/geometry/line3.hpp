/**
 * @file geometry/line3.hpp
 * @copyright Copyleft zukonake
 * @license Distributed under GNU General Public License Version 3
 */

#pragma once

#include <cmath>
#include <vector>
//
#include <geometry/vector3.hpp>

namespace coldline
{

namespace geometry
{

template< typename TCoordinate >
struct Line3
{
	typedef Vector3< TCoordinate > Point;
	typedef Vector3< double > Center;
	typedef std::vector< Point > Plot;
	typedef double Length;

	constexpr Line3() noexcept = default;
	constexpr Line3( Line3 const &that ) noexcept = default;
	constexpr Line3( Point const &from, Point const &to ) noexcept;
	template < typename T >
	constexpr Line3( Line3< T > const &that ) noexcept;

	template< typename T >
	constexpr operator Line3< T >();

	constexpr Line3< TCoordinate > &operator=( Line3 const &that );
	constexpr Line3< TCoordinate > &operator+( Line3 const &that );
	constexpr Line3< TCoordinate > &operator-( Line3 const &that );

	constexpr Line3< TCoordinate > &operator+=( Line3 const &that );
	constexpr Line3< TCoordinate > &operator-=( Line3 const &that );

	constexpr bool operator==( Line3 const &that );
	constexpr bool operator!=( Line3 const &that );
	constexpr bool operator<=( Line3 const &that );
	constexpr bool operator>=( Line3 const &that );
	constexpr bool operator<( Line3 const &that );
	constexpr bool operator>( Line3 const &that );

	constexpr Length getLength() const noexcept;
	constexpr Center getCenter() const noexcept;
	Plot getPlot() const noexcept;
	Plot getBounds() const noexcept;

	Point from;
	Point to;
};

}

}
