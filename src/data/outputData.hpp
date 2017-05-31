#pragma once

#include <queue>
//
#include <render/transformedDrawable.hpp>

namespace coldline
{

struct OutputData
{
	std::queue< TransformedDrawable > renderQueue;
	bool playing = true;
};

}
