#pragma once

#include <data/loadable.hpp>
#include <render/renderTile.hpp>

namespace coldline
{

class Dataset;
class DataMap;

class EntitySubtype : public Loadable
{
	public:
	EntitySubtype( Dataset const &dataset, DataMap const &dataMap );
	EntitySubtype( RenderTile const &renderTile, bool const &solid ) noexcept;

	RenderTile mRenderTile;
	bool mSolid;
};

}
