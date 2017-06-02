#pragma once

#include <world/generator/generator.hpp>

namespace coldline
{

namespace world
{

class Dataset;

class FlatGenerator : public Generator
{
	public:
	FlatGenerator( Dataset const &dataset );

	virtual Chunk generate( chunk::Point const &position ) override;
	private:
	Dataset const &mDataset;
};

}

}
