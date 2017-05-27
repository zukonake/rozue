#include <render/sprite.hpp>
#include <render/renderable.hpp>
#include "transformedSprite.hpp"

TransformedSprite::TransformedSprite( Renderable const &renderable ) :
	mRenderable( renderable )
{
	
}

void TransformedSprite::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	states.transform.combine( sf::Transformable::getTransform());
	target.draw( mRenderable.getSprite(), states );
}
