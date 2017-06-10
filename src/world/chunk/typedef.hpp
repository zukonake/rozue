#pragma once

#include <geometry/vector3.hpp>

namespace coldline
{

typedef long long ChunkCoordinate;
typedef unsigned ChunkInternalCoordinate;
typedef unsigned ChunkLength;
typedef ::coldline::geometry::Vector3< ChunkCoordinate > ChunkPoint;
typedef ::coldline::geometry::Vector3< ChunkInternalCoordinate > ChunkInternalPoint;
typedef ::coldline::geometry::Vector3< ChunkLength > ChunkSize;

}
