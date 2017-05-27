#pragma once

#include <cstdint>
//
#include <geometry/point.hpp>
#include <geometry/size.hpp>
#include <world/map.hpp>
#include <world/generator/generator.hpp>

class Tile;
class Dataset;
class World;

class DungeonGenerator : public Generator
{
	struct Dungeon
	{
		Size2 size;
		Point2 position;
	};
	struct Corridor
	{
		Point2 from;
		Point2 to;
	};
	public:
	DungeonGenerator( Dataset const &dataset, Size2 const &minSize, Size2 const &maxSize, float const &density );

	virtual World generate() override;
	private:
	Dungeon randomizeDungeon();
	void generateDungeons( uint16_t const &number );
	void applyDungeons( Map &map, Tile const &fill );
	void generateCorridors();
	void applyCorridors( Map &map, Tile const &fill );
	void placeMonsters( World &world, uint16_t const &number );

	bool good( Dungeon const &dungeon, uint16_t level );

	static bool touches( Dungeon const &one, Dungeon const &two );
	static bool intersects( Dungeon const &one, Dungeon const &two );
	static uint16_t getDistance( Point2 const &from, Point2 const &to );
	static Point2 getOrigin( Dungeon const &dungeon );

	std::vector< Dungeon > mDungeons[ global::mapSize.z ];
	std::vector< Corridor > mCorridors[ global::mapSize.z ];

	Size2 const mMinSize; //TODO should it really be const?
	Size2 const mMaxSize;
	float const mDensity;
	Dataset const &mDataset;
};
