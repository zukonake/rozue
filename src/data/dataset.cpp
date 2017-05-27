#include <global.hpp>
#include <render/tileset.hpp>
#include <render/sprite.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/entity/entitySubtype.hpp>
#include "dataset.hpp"

Tileset const mainTileset =
{
	"tilesets/mainTileset.png",
	{ 16, 16 }
};

Sprite const nothing = 
{
	mainTileset,
	{ 0, 0 }
};

TileSubtype const stoneFloor = 
{
	{
		mainTileset,
		{ 1, 0 }
	},
	false
};

TileSubtype const stoneWall = 
{
	{
		mainTileset,
		{ 2, 0 }
	},
	true
};

EntitySubtype const human = 
{
	{
		mainTileset,
		{ 3, 0 }
	}
};

EntitySubtype const goblin = 
{
	{
		mainTileset,
		{ 4, 0 }
	}
};

Dataset::Dataset()
{
	mObjects[ "mainTileset" ] = &mainTileset;
	mObjects[ "nothing" ] = &nothing;
	mObjects[ "stoneFloor" ] = &stoneFloor;
	mObjects[ "stoneWall" ] = &stoneWall;
	mObjects[ "human" ] = &human;
	mObjects[ "goblin" ] = &goblin;
}
