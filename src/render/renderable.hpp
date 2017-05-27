#pragma once

class Sprite;

class Renderable
{
	public:
	virtual Sprite const &getSprite() const = 0;
};
