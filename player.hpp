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

	auto on_key_press(const sf::Event::KeyEvent key_press) -> void {
		direction = direction + key_to_direction(key_press.code);
	}

	auto on_key_release(const sf::Event::KeyEvent key_release) -> void {
		direction = direction - key_to_direction(key_release.code);
	}

	static auto normalize(const sf::Vector2f vec) -> sf::Vector2f {
		auto len_squared = [](const sf::Vector2f v) -> float {
			return v.x * v.x + v.y * v.y;
		};

		const auto len_sq = len_squared(vec);
		if (len_sq == 0.0F) {
			return vec;
		}

		return vec / std::sqrt(len_sq);
	}

	static auto key_to_direction(const sf::Keyboard::Key key) -> sf::Vector2f {
		switch (key) {
		case sf::Keyboard::Key::W: {
			return up;
		}
		case sf::Keyboard::Key::A: {
			return left;
		}
		case sf::Keyboard::Key::S: {
			return down;
		}
		case sf::Keyboard::Key::D: {
			return right;
		}
		default: {
			return { 0.0F, 0.0F };
		}
		}
	}

	auto move(const float speed) -> void {
		const auto normalized_direction = normalize(direction);

		box.move(normalized_direction * speed);
	}
private:
	static inline const auto up	   = sf::Vector2f{ 0.0F, -1.0F };
	static inline const auto down  = -up;
	static inline const auto right = sf::Vector2f{ 1.0F, 0.0F };
	static inline const auto left  = -right;

	sf::RectangleShape	  box{};
	sf::Vector2f		  direction{ 0.0F, 0.0F };
	static constexpr auto BOX_SIZE_PX = 10;
};

#endif // SNAKE_PLAYER_HPP
