#pragma once

#include <cstdint>
//
#include <geometry/point.hpp>
#include <geometry/size.hpp>
#include <world/map.hpp>
#include <world/generator/generator.hpp>

class Tile;
class World;

class DungeonGenerator : public Generator
{
	struct Dungeon
	{
		Size2 size;
		Point position;
	};
	public:
	DungeonGenerator( Size2 const &minSize, Size2 const &maxSize, float const &density );

	virtual World generate() override;
	private:
	Dungeon randomizeDungeon();
	void generateDungeons( uint16_t const &number );
	void applyDungeons( Map &map, Tile const &fill );
	bool good( Dungeon const &dungeon );

	static bool touches( Dungeon const &one, Dungeon const &two );
	static bool intersects( Dungeon const &one, Dungeon const &two );

	std::vector< Dungeon > mDungeons;

	Size2 const mMinSize;
	Size2 const mMaxSize;
	float const mDensity;
};
