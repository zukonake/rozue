#pragma once

#include <data/loadable.hpp>
#include <render/tile.hpp>

namespace coldline
{

class Dataset;
class DataMap;

class TileSubtype : public Loadable
{
	public:
	TileSubtype( Dataset const &dataset, DataMap const &dataMap );
	TileSubtype( render::Tile const &renderTile, bool const &solid ) noexcept;

	render::Tile mRenderTile;
	bool mSolid;
};

}
