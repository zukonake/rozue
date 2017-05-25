#pragma once

class World;

class Generator
{
	protected:
	Generator() = default;
	public:
	virtual World generate() = 0;
	operator World();
};
