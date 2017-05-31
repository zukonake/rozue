#pragma once

#include <SFML/Graphics/Drawable.hpp>

namespace sf
{
	class Transform;
}

namespace coldline
{

class TransformedDrawable : public sf::Drawable
{
	public:
	TransformedDrawable( sf::Transform const &transform, sf::Drawable const &drawable );

	virtual void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

	private:
	sf::Transform const &mTransform;
	sf::Drawable const &mDrawable;
};

}
