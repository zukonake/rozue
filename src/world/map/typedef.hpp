#pragma once

#include <geometry/vector2.hpp>
#include <geometry/vector3.hpp>
#include <geometry/line2.hpp>
#include <geometry/line3.hpp>
#include <geometry/rectangle.hpp>
#include <geometry/cuboid.hpp>

namespace coldline
{

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
typedef ::coldline::geometry::Rectangle< Coordinate, Length > Surface;
typedef ::coldline::geometry::Cuboid< Coordinate, Length > Space;

}

}
