#pragma once

#include <data/loadable.hpp>
#include <render/sprite.hpp>

class Dataset;
class DataMap;

class TileSubtype : public Sprite, public virtual Loadable
{
	public:
	TileSubtype( Dataset const &dataset, DataMap const &dataMap );
	TileSubtype( Sprite const &sprite, bool const &solid );

	bool passable() const noexcept;
	private:
	bool mSolid;
};
