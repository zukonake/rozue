#pragma once

#include <geometry/map3.hpp>
#include <world/map/chunk/typedef.hpp>
#include <world/tile/tile.hpp>

namespace coldline
{

chunk::Size constexpr chunkSize = { 32, 32, 1 };
typedef ::coldline::geometry::Map3< Tile, chunkSize.x, chunkSize.y, chunkSize.z > Chunk;

}
