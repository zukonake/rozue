#pragma once

#include <SFML/Graphics.hpp>
//
#include <geometry/point.hpp>
#include <geometry/size.hpp>
#include <data/loadable.hpp>
#include <render/renderable.hpp>

struct Tileset;

class DataMap;
class Dataset;

class Sprite : public virtual Loadable, public virtual Renderable, public sf::Drawable
{
	public:
	Sprite( Dataset const &dataset, DataMap const &dataMap );
	Sprite( Tileset const &tileset, Point2 const &tilesetPosition );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;
	virtual Sprite const &getSprite() const override;
	Size2 const &getSize() const noexcept;
	private:
	Tileset const &mTileset;
	Point2 mTilesetPosition;
};
