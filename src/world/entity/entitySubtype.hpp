#pragma once

#include <data/loadable.hpp>
#include <render/tile.hpp>

namespace coldline
{

class Dataset;
class DataMap;

class EntitySubtype : public virtual Loadable
{
	public:
	EntitySubtype( Dataset const &dataset, DataMap const &dataMap );
	EntitySubtype( render::Tile const &renderTile, bool const &solid );

	render::Tile mTile;
	bool mSolid;
};

}
