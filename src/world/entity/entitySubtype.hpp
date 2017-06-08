#pragma once

#include <data/loadable.hpp>
#include <render/tile.hpp>

namespace coldline
{

class Dataset;
class DataMap;

class EntitySubtype : public Loadable
{
	public:
	EntitySubtype( Dataset const &dataset, DataMap const &dataMap );
	EntitySubtype( render::Tile const &renderTile, bool const &solid ) noexcept;

	render::Tile mRenderTile;
	bool mSolid;
};

}
