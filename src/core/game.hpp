#pragma once

#include <SFML/Graphics.hpp>
//
#include <world/world.hpp>
#include <core/camera.hpp>

class Game
{
	public:
	Game();

	~Game() = default;

	void start(); //TODO maybe add threads
	private:
	void loop();
	void render();
	void handleInput();
	void handleKey( sf::Keyboard::Key const &key );

	World mWorld;
	Camera mCamera;
	sf::RenderWindow mScreen;
	sf::Texture mTileset;
	bool mPlaying;
};
