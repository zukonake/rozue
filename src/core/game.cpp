#include <SFML/Graphics.hpp>
//
#include <world/generator/dungeonGenerator.hpp>
#include "game.hpp"

Game::Game() :
	mWorld( DungeonGenerator({ 3, 3 }, { 10, 10 }, 1.3f )),
	mCamera( mWorld ),
	mScreen( sf::VideoMode( 800, 600 ),
		"Rozue",
		sf::Style::Titlebar )
{
	mTileset.loadFromFile( "tileset.png" );
}

void Game::start()
{
	mPlaying = true;
	loop();
}

void Game::loop()
{
	while( mPlaying )
	{
		render();
		handleInput();
	}
}

void Game::render()
{
	mScreen.clear( sf::Color::Black );
	mScreen.draw( mCamera, &mTileset );
	mScreen.display();
}

void Game::handleInput()
{
	sf::Event event;
	while( mScreen.pollEvent( event ))
	{
		switch( event.type )
		{
		case sf::Event::Closed:
			mPlaying = false;
			break;

		case sf::Event::KeyPressed:
			handleKey( event.key.code );
			break;

		default:
			break;
		}
		break;
	}
}

void Game::handleKey( sf::Keyboard::Key const &key )
{
	switch( key )
	{
	case sf::Keyboard::Escape:
		mPlaying = false;
		break;

	case sf::Keyboard::W:
		mCamera.move({ 0, -1, 0 });
		break;

	case sf::Keyboard::A:
		mCamera.move({ -1, 0, 0 });
		break;

	case sf::Keyboard::S:
		mCamera.move({ 0, 1, 0 });
		break;

	case sf::Keyboard::D:
		mCamera.move({ 1, 0, 0 });
		break;

	case sf::Keyboard::R:
		mCamera.unlock();
		break;

	case sf::Keyboard::F:
		mCamera.lock();
		break;

	default:
		break;
	}
}
