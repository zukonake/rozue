#pragma once

#include <queue>
//
#include <render/sprite.hpp>
#include <render/tileMap.hpp>

namespace coldline
{

struct OutputData
{
	std::queue< Sprite > renderQueue;
	TileMap tileMap;
	bool playing = true;
};

}
