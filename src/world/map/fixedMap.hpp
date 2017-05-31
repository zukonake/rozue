#pragma once

#include <point.hpp>
#include <world/map/map.hpp>
#include <world/tile/tile.hpp>

namespace coldline
{

class TileSubtype;

template< unsigned long long width, unsigned long long height, unsigned long long depth >
class FixedMap : public Map
{
	public:
	FixedMap( TileSubtype const &fill );

	virtual Tile &operator[]( Point3 const &point ) override;
	virtual Tile const &at( Point3 const &point ) const override;
	private:
	geometry::Map3< Tile, width, height, depth > mValue;
};

}
