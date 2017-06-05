#pragma once

#include <queue>
//
#include <render/sprite.hpp>

namespace coldline
{

struct OutputData
{
	std::queue< Sprite > renderQueue;
	bool playing = true;
};

}
