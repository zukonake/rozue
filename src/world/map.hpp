#pragma once

#include <coldline-geometry/map3.hpp>
//
#include <global.hpp>
#include <world/tile/tile.hpp>

typedef coldline::geometry::Map3<
	Tile,
	global::mapSize.x,
	global::mapSize.y,
	global::mapSize.z > Map;
