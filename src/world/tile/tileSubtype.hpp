#pragma once

#include <data/loadable.hpp>
#include <render/tile.hpp>

namespace coldline
{

class Dataset;
class DataMap;

class TileSubtype : public virtual Loadable
{
	public:
	TileSubtype( Dataset const &dataset, DataMap const &dataMap );
	TileSubtype( render::Tile const &renderTile, bool const &solid );

	render::Tile mTile;
	bool mSolid;
};

}
