#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

constexpr auto TARGET_FPS = 60;

constexpr auto WINDOW_WIDTH	 = 800;
constexpr auto WINDOW_HEIGHT = 600;

auto main() -> int {
	constexpr auto window_style = sf::Style::Titlebar | sf::Style::Close;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "What the hell is this",
							window_style);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(TARGET_FPS);

	sf::VertexBuffer buffer{ sf::LineStrip, sf::VertexBuffer::Usage::Dynamic };

	constexpr auto buffer_size = 1000;
	buffer.create(buffer_size);

	buffer.getVertexCount();

	auto vertex_counter = 0;

	while (window.isOpen()) {
		sf::Event event{};
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed: {
				window.close();
				break;
			}
			case sf::Event::MouseButtonPressed: {
				const auto button = event.mouseButton;

				const sf::Vertex point{ sf::Vector2f(static_cast<float>(button.x),
													 static_cast<float>(button.y)),
										sf::Color::Green };

				buffer.update(&point, 1, vertex_counter);

				++vertex_counter;
				break;
			}
			default:
				break;
			}
		}

		window.clear(sf::Color::Black);
		if (vertex_counter > 1) {
			window.draw(buffer, 0, vertex_counter);
		}

		window.display();
	}

	return EXIT_SUCCESS;
}