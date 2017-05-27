#pragma once

#include <cstdint>
#include <string>
//
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//
#include <geometry/size.hpp>

class SFMLClient : public sf::Transformable
{
public:
	SFMLClient() = default;

	virtual ~SFMLClient() noexcept;

	void update() noexcept;
	void draw( sf::Drawable const &drawable, sf::RenderStates states = sf::RenderStates::Default );

	void openWindow( Size2 const &windowSize, std::string const &windowTitle, uint8_t fpsLimit = 0, bool vsync = false, uint8_t antialiasingLevel = 0 );

	bool isRunning() const noexcept;
	bool isKeyPressed( sf::Keyboard::Key key ) const noexcept;

	std::vector< sf::Event > getEvents() noexcept;
	sf::RenderWindow& getWindow() noexcept;
	sf::View& getView() noexcept;
	Size2 getWindowSize() const noexcept;
private:
	sf::View mView;
	sf::ContextSettings mSettings;
	sf::RenderWindow mWindow;
	sf::Event mEvent;
	sf::Keyboard mKeyboard;
};
