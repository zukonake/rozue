#include <SFML/Graphics.hpp>
//
#include <world/generator/dungeonGenerator.hpp>
#include "game.hpp"

Game::Game() :
	mWorld( DungeonGenerator({ 4, 4 }, { 7, 7 }, 0.75f )),
	mCamera( mWorld ),
	mScreen( sf::VideoMode( 1024, 768 ),
		"Rozue",
		sf::Style::Titlebar )
{
	mTileset.loadFromFile( "tileset16x16.png" );
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

	case sf::Keyboard::Q:
		mCamera.changeScale( 0.25f );
		break;

	case sf::Keyboard::E:
		mCamera.changeScale( -0.25f );
		break;

	default:
		break;
	}
}
