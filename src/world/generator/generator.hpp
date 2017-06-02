#pragma once

#include <world/map/chunk/typedef.hpp>
#include <world/map/chunk/chunk.hpp>

namespace coldline
{

namespace world
{

class Generator
{
	public:
	virtual ~Generator() = default;

	virtual Chunk generate( chunk::Point const &position ) = 0;
};

}

}
