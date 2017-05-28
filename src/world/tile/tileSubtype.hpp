#pragma once

#include <data/loadable.hpp>
#include <render/sprite.hpp>

class Dataset;
class DataMap;

class TileSubtype : public Sprite, public virtual Loadable
{
	friend class Tile;
	public:
	TileSubtype( Dataset const &dataset, DataMap const &dataMap );
	TileSubtype( Sprite const &sprite, bool const &solid );

	private:
	bool mSolid;
};
