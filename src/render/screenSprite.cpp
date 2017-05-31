#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
//
#include "transformedDrawable.hpp"

namespace coldline
{

TransformedDrawable::TransformedDrawable( sf::Transform const &transform, sf::Drawable const &drawable ) :
	mTransform( transform ),
	mDrawable( drawable )
{

}

void TransformedDrawable::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
	states.transform.combine( mTransform );
	target.draw( mDrawable, states );
}

}
