#pragma once

#include <world/generator/generator.hpp>

namespace coldline
{

class Dataset;

class WallGenerator : public Generator
{
	public:
	WallGenerator( Dataset const &dataset );

	virtual Chunk generate( chunk::Point const &position ) override;
	private:
	Dataset const &mDataset;
};

}
