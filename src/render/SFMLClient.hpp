#pragma once

#include <string>
//
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//
#include <render/typedef.hpp>

namespace coldline
{

class SFMLClient : public sf::Transformable
{
public:
	SFMLClient() = default;

	virtual ~SFMLClient() noexcept;

	void update() noexcept;
	void draw( sf::Drawable const &drawable, sf::RenderStates states = sf::RenderStates::Default );

	void openWindow( render::Size const &windowSize,
		std::string const &windowTitle,
		unsigned short fpsLimit = 0,
		bool vsync = false,
		unsigned short antialiasingLevel = 0 );

	bool isRunning() const noexcept;
	bool isKeyPressed( sf::Keyboard::Key key ) const noexcept;

	std::vector< sf::Event > getEvents() noexcept;
	sf::RenderWindow& getWindow() noexcept;
	sf::View& getView() noexcept;
	render::Size getWindowSize() const noexcept;
private:
	sf::View mView;
	sf::ContextSettings mSettings;
	sf::RenderWindow mWindow;
	sf::Event mEvent;
	sf::Keyboard mKeyboard;
};

}
