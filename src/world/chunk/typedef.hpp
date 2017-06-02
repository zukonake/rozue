#pragma once

#include <geometry/vector3.hpp>

namespace coldline
{

namespace chunk
{

typedef long long Coordinate;
typedef unsigned InternalCoordinate;
typedef unsigned Length;
typedef ::coldline::geometry::Vector3< Coordinate > Point;
typedef ::coldline::geometry::Vector3< InternalCoordinate > InternalPoint;
typedef ::coldline::geometry::Vector3< Length > Size;

}

}
