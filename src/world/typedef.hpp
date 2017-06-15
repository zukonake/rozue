#pragma once

#include <geometry/vector3.hpp>
#include <geometry/line3.hpp>
#include <geometry/cuboid.hpp>
#include <geometry/map3.hpp>

namespace coldline
{

class Tile;

typedef long long WorldCoordinate;
typedef unsigned long long WorldLength;
typedef ::coldline::geometry::Vector3< WorldCoordinate > WorldPoint;
typedef ::coldline::geometry::Vector3< WorldCoordinate > WorldVector;
typedef ::coldline::geometry::Line3< WorldCoordinate > WorldLine;
typedef ::coldline::geometry::Cuboid< WorldCoordinate, WorldLength > WorldSpaceScope;
template< WorldLength width, WorldLength height, WorldLength depth >
using WorldSpace = ::coldline::geometry::Map3< Tile, width, height, depth >;

}
