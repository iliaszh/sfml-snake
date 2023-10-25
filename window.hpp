#ifndef SNAKE_WINDOW_HPP
#define SNAKE_WINDOW_HPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Window {
public:
	Window()
		: window{ sf::VideoMode{ WINDOW_WIDTH, WINDOW_HEIGHT }, TITLE, WINDOW_STYLE } {
		window.setVerticalSyncEnabled(VSYNC_ENABLED);
		window.setFramerateLimit(TARGET_FPS);
	}

	auto draw(std::vector<sf::Drawable> drawables) -> void {

	}
private:
	sf::RenderWindow window{};

	static constexpr auto TARGET_FPS = 60;

	static constexpr auto WINDOW_WIDTH	= 800;
	static constexpr auto WINDOW_HEIGHT = 600;

	static constexpr auto WINDOW_STYLE = sf::Style::Titlebar | sf::Style::Close;

	static constexpr auto VSYNC_ENABLED = true;

	static constexpr auto TITLE = "SFML game";
};

#endif // SNAKE_WINDOW_HPP
