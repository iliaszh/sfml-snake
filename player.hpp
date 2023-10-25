#ifndef SNAKE_PLAYER_HPP
#define SNAKE_PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
	explicit Player(sf::Color fill_color = sf::Color::Red)
		: box{ sf::Vector2f{ BOX_SIZE_PX, BOX_SIZE_PX } } {
		box.setFillColor(fill_color);
	}

	auto drawable() const -> const sf::Drawable& {
		return box;
	}

	auto set_position(const sf::Vector2f pos) -> void {
		box.setPosition(pos);
	}

	auto get_box() -> sf::Vector2f {
		return box.getSize();
	}

	auto set_rotation(const float angle_degrees) -> void {
		box.setRotation(angle_degrees);
	}

	auto on_key_press(sf::Event::KeyEvent key_press) -> void {
		switch (key_press.code) {
		case sf::Keyboard::Key::W: {
			box.move(sf::Vector2f{ 0.0F, -BOX_SIZE_PX });
			break;
		}
		case sf::Keyboard::Key::A: {
			box.move(sf::Vector2f{ -BOX_SIZE_PX, 0.0F });
			break;
		}
		case sf::Keyboard::Key::S: {
			box.move(sf::Vector2f{ 0.0F, +BOX_SIZE_PX });
			break;
		}
		case sf::Keyboard::Key::D: {
			box.move(sf::Vector2f{ BOX_SIZE_PX, 0.0F });
			break;
		}
		default:
			break;
		}
	}
private:
	sf::RectangleShape box{};

	static constexpr auto BOX_SIZE_PX = 10;
};

#endif // SNAKE_PLAYER_HPP
