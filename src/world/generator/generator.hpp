#pragma once

#include <geometry/map3.hpp>
//
#include <world/map/typedef.hpp>

namespace coldline
{

class Tile;
class Dataset;

template< map::Length width, map::Length height, map::Length depth >
class Generator
{
	public:
	Generator( Dataset const &mDataset );
	virtual geometry::Map3< Tile, width, height, depth > generate( map::Point3 const &position ) = 0;
};

}
