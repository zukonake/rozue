#pragma once

#include <data/loadable.hpp>
#include <render/renderTile.hpp>

namespace coldline
{

class Dataset;
class DataMap;

class TileSubtype : public Loadable
{
	public:
	TileSubtype( Dataset const &dataset, DataMap const &dataMap );
	TileSubtype( RenderTile const &renderTile, bool const &solid ) noexcept;

	RenderTile mRenderTile;
	bool mSolid;
};

}
