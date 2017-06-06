#pragma once

#include <geometry/vector2.hpp>
#include <geometry/line2.hpp>
#include <geometry/rectangle.hpp>

namespace coldline
{

namespace render
{

typedef float Coordinate;
typedef float Length;
typedef ::coldline::geometry::Vector2< Coordinate > Point;
typedef ::coldline::geometry::Vector2< Coordinate > Scale;
typedef ::coldline::geometry::Vector2< Coordinate > Size;
typedef ::coldline::geometry::Vector2< Coordinate > Vector;
typedef ::coldline::geometry::Line2< Coordinate > Line;
typedef ::coldline::geometry::Rectangle< Coordinate, Length > Surface;

}

}

