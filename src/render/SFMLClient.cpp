#include <stdexcept>
//
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
//
#include <render/typedef.hpp>
#include "SFMLClient.hpp"

namespace coldline
{

SFMLClient::~SFMLClient()
{
	mWindow.close();
}

void SFMLClient::update() noexcept
{
	mWindow.display();
	mWindow.clear( sf::Color::Black );
}

void SFMLClient::draw( sf::Drawable const &drawable, sf::RenderStates states )
{
	mWindow.draw( drawable, states );
}

void SFMLClient::openWindow( RenderSize const &windowSize,
	std::string const &windowTitle,
	unsigned short fpsLimit,
	bool vsync,
	unsigned short antialiasingLevel ) //TODO change to screenConfig?
{
	mSettings.antialiasingLevel = antialiasingLevel;
	mWindow.create( sf::VideoMode( windowSize.x, windowSize.y, 32 ),
		windowTitle,
		sf::Style::Titlebar,
		mSettings );
	if( !mWindow.isOpen() )
	{
		throw std::runtime_error( "SFMLClient::openWindow: couldn't initialize window" );
		return;
	}
	mWindow.clear( sf::Color( 0, 0, 0 ) );
	mWindow.setVerticalSyncEnabled( vsync );
	mWindow.setFramerateLimit( fpsLimit );
}

bool SFMLClient::isRunning() const noexcept
{
	return mWindow.isOpen();
}

bool SFMLClient::isKeyPressed( sf::Keyboard::Key key ) const noexcept
{
	return mKeyboard.isKeyPressed( key );
}

std::vector< sf::Event > SFMLClient::getEvents() noexcept
{
	std::vector< sf::Event > output;
	while( mWindow.pollEvent( mEvent ) )
	{
		output.push_back( mEvent );
	}
	return output;
}

sf::RenderWindow& SFMLClient::getWindow() noexcept
{
	return mWindow;
}

RenderSize SFMLClient::getWindowSize() const noexcept
{
	return static_cast< RenderSize >( mWindow.getSize());
}

}
