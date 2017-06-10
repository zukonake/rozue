#pragma once

#include <world/generator/generator.hpp>

namespace coldline
{

class TileSubtype;
class Dataset;

class WallGenerator : public Generator
{
	public:
	WallGenerator( Dataset const &dataset );

	virtual Chunk generate( ChunkPoint const &position ) override;
	private:
	TileSubtype const &mWall;
	TileSubtype const &mFloor;
};

}
