#pragma once

#include <world/chunk/typedef.hpp>

namespace coldline
{

class Chunk;

class Generator
{
	public:
	virtual ~Generator() = default;

	virtual Chunk generate( ChunkPoint const &position ) = 0;
};

}
