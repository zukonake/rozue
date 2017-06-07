#include <data/config.hpp>
#include <render/tileset.hpp>
#include <render/tile.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/entity/entitySubtype.hpp>
#include "dataset.hpp"

namespace coldline
{

Config const config =
{
	{ 1024, 768 },
	{ 64, 64 }
};

Tileset const tilesTileset =
{
	"tilesets/tiles.png",
	{ 16, 16 }
};

Tileset const entitiesTileset =
{
	"tilesets/entities.png",
	{ 16, 16 }
};

Tileset const creaturesTileset =
{
	"tilesets/creatures.png",
	{ 16, 16 }
};

render::Tile const nothing =
{
	tilesTileset,
	{ 0, 0 }
};

TileSubtype const stoneFloor =
{
	{
		tilesTileset,
		{ 1, 0 }
	},
	false
};

TileSubtype const stoneWall =
{
	{
		tilesTileset,
		{ 2, 0 }
	},
	true
};

EntitySubtype const human =
{
	{
		creaturesTileset,
		{ 0, 0 }
	},
	false
};

EntitySubtype const goblin =
{
	{
		creaturesTileset,
		{ 1, 0 }
	},
	false
};

EntitySubtype const door =
{
	{
		entitiesTileset,
		{ 0, 0 }
	},
	true
};

Dataset::Dataset()
{
	mObjects[ "config" ] = &config;
	mObjects[ "tilesTileset" ] = &tilesTileset;
	mObjects[ "nothing" ] = &nothing;
	mObjects[ "stoneFloor" ] = &stoneFloor;
	mObjects[ "stoneWall" ] = &stoneWall;
	mObjects[ "human" ] = &human;
	mObjects[ "goblin" ] = &goblin;
	mObjects[ "door" ] = &door;
}

}
