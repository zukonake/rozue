#pragma once

#include <queue>
//
#include <geometry/point.hpp>
#include <render/transformedSprite.hpp>

struct OutputData
{
	std::queue< TransformedSprite > sprites;
	bool playing = true;
	float zoom = 1;
	Point2 viewPosition;
};
