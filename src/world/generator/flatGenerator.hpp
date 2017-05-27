#pragma once

#include <world/generator/generator.hpp>

class Dataset;
class World;

class FlatGenerator : public Generator
{
	public:
	FlatGenerator( Dataset const &dataset );

	virtual World generate() override;
	private:
	Dataset const &mDataset;
};
