#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

auto main() -> int {
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::Black);
		// draw everything here...
		// window.draw(...);
		window.display();
	}

	return 0;
}