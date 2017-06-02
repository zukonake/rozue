#pragma once

#include <geometry/vector2.hpp>
#include <geometry/vector3.hpp>
#include <geometry/line2.hpp>
#include <geometry/line3.hpp>
#include <geometry/rectangle.hpp>
#include <geometry/cuboid.hpp>
#include <geometry/map2.hpp>
#include <geometry/map3.hpp>

namespace coldline
{

class Tile;

namespace map
{

typedef long long Coordinate;
typedef unsigned long long Length;
typedef ::coldline::geometry::Vector2< Coordinate > Point2;
typedef ::coldline::geometry::Vector3< Coordinate > Point3;
typedef ::coldline::geometry::Vector2< Coordinate > Vector2;
typedef ::coldline::geometry::Vector3< Coordinate > Vector3;
typedef ::coldline::geometry::Line2< Coordinate > Line2;
typedef ::coldline::geometry::Line3< Coordinate > Line3;
typedef ::coldline::geometry::Rectangle< Coordinate, Length > SurfaceScope;
typedef ::coldline::geometry::Cuboid< Coordinate, Length > SpaceScope;
template< Length width, Length height >
using Surface = ::coldline::geometry::Map2< Tile, width, height >;
template< Length width, Length height, Length depth >
using Space = ::coldline::geometry::Map3< Tile, width, height, depth >;

}

}
