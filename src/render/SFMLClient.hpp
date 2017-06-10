#pragma once

#include <string>
#include <vector>
//
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
//
#include <render/typedef.hpp>

namespace coldline
{

class SFMLClient
{
public:
	virtual ~SFMLClient();

	void update() noexcept;
	void draw( sf::Drawable const &drawable, sf::RenderStates states = sf::RenderStates::Default );

	void openWindow( RenderSize const &windowSize,
		std::string const &windowTitle,
		unsigned short fpsLimit = 0,
		bool vsync = false,
		unsigned short antialiasingLevel = 0 );

	bool isRunning() const noexcept;
	bool isKeyPressed( sf::Keyboard::Key key ) const noexcept;

	std::vector< sf::Event > getEvents() noexcept;
	sf::RenderWindow& getWindow() noexcept;
	RenderSize getWindowSize() const noexcept;
private:
	sf::ContextSettings mSettings;
	sf::RenderWindow mWindow;
	sf::Event mEvent;
	sf::Keyboard mKeyboard;
};

}
