#pragma once

#include <SFML/Graphics/Drawable.hpp>
//
#include <render/typedef.hpp>
#include <data/loadable.hpp>

namespace coldline
{

class Tileset;

class DataMap;
class Dataset;

class Sprite : public virtual Loadable, public virtual sf::Drawable
{
	public:
	Sprite( Dataset const &dataset, DataMap const &dataMap );
	Sprite( Tileset const &tileset, screen::Point const &tilesetPosition );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	screen::Size const &getSize() const noexcept;
	private:
	Tileset const &mTileset;
	screen::Point mTilesetPosition;
};

}
