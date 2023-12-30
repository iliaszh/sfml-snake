#include <print>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "player.hpp"

constexpr auto TARGET_FPS = 165;

constexpr auto WINDOW_WIDTH	 = 800;
constexpr auto WINDOW_HEIGHT = 600;

auto main() -> int {
	const auto	   video_mode	= sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
	constexpr auto window_style = sf::Style::Titlebar | sf::Style::Close;
	constexpr auto window_title = "What the hell is this";

	sf::RenderWindow window(video_mode, window_title, window_style);
	window.setVerticalSyncEnabled(false);
	// window.setFramerateLimit(TARGET_FPS);
	window.setKeyRepeatEnabled(false);

	const auto window_center = sf::Vector2f{ WINDOW_WIDTH / 2.0F, WINDOW_HEIGHT / 2.0F };

	auto player = Player{ sf::Color::Red };
	player.set_position(window_center - 0.5F * player.get_box());

	auto key_press_counter = 0;

	while (window.isOpen()) {
		sf::Event event{};
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed: {
				window.close();
				break;
			}
			case sf::Event::KeyPressed: {
				player.on_key_press(event.key);
				std::println("key pressed {}, key code {}", key_press_counter++,
							 static_cast<int>(event.key.code));

				break;
			}
			case sf::Event::KeyReleased: {
				player.on_key_release(event.key);
				std::println("key released, key code {}", static_cast<int>(event.key.code));
				break;
			}
			case sf::Event::JoystickConnected: {
				std::println("joystick connected");
				break;
			}
			case sf::Event::JoystickDisconnected: {
				std::println("joystick disconnected");
				break;
			}
			case sf::Event::JoystickButtonPressed: {
				const auto button = event.joystickButton;
				std::println("joystick button {} pressed", button.button);
				break;
			}
			case sf::Event::JoystickButtonReleased: {
				const auto button = event.joystickButton;
				std::println("joystick button {} released", button.button);
				break;
			}
			case sf::Event::JoystickMoved: {
				const auto move = event.joystickMove;
				std::println("joystick axis {} moved {}", static_cast<int>(move.axis),
							 move.position);

				break;
			}
			default:
				break;
			}
		}

		window.clear(sf::Color::Black);

		player.move(0.05F);
		window.draw(player.drawable());

		window.display();
	}

	return EXIT_SUCCESS;
}
