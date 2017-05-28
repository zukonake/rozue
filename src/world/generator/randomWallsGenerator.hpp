#pragma once

#include <world/generator/generator.hpp>

class Dataset;
class World;

class RandomWallsGenerator : public Generator
{
	public:
	RandomWallsGenerator( Dataset const &dataset, float const &density );

	virtual World generate() override;
	private:
	Dataset const &mDataset;
	float mDensity;
};
