#pragma once

#include <world/generator/generator.hpp>

class World;

class FlatGenerator : public Generator
{
	public:
	FlatGenerator() = default;

	virtual World generate() override;
};
