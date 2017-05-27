#pragma once

#include <SFML/Graphics.hpp>

class Renderable;

class TransformedSprite : public sf::Transformable, public virtual sf::Drawable
{
	public:
	TransformedSprite( Renderable const &renderable );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;
	private:
	Renderable const &mRenderable;
};
