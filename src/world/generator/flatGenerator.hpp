#pragma once

#include <world/generator/generator.hpp>

namespace coldline
{

class TileSubtype;
class Dataset;

class FlatGenerator : public Generator
{
	public:
	FlatGenerator( Dataset const &dataset );

	virtual Chunk generate( chunk::Point const &position ) override;
	private:
	TileSubtype const &mFloor;
};

}
