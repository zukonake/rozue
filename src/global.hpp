#pragma once

#include <cstddef>
//
#include <geometry/size.hpp>
#include <geometry/scale.hpp>

namespace global
{

Size3 constexpr mapSize( 100, 100, 5 );
Size2 constexpr textureSpriteSize( 16, 16 );
Size2 constexpr screenSpriteSize( 48, 48 );
Scale2 constexpr spriteScale( screenSpriteSize / textureSpriteSize );

}
