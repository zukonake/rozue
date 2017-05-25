#pragma once

#include <global.hpp>
#include <world/tile/tileSubtype.hpp>

TileSubtype const stoneFloor
{ 
	{ 0 * global::spriteSize.x, 0 * global::spriteSize.y },
	false
};

TileSubtype const stoneWall
{ 
	{ 1 * global::spriteSize.x, 0 * global::spriteSize.y },
	true
};
