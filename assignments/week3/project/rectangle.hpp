#pragma once

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class rectangle : public drawable {
private:
  sf::RectangleShape rect;

public:
  rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color);
  void draw(sf::RenderWindow &window) const;
  sf::FloatRect getBounds() const;
  void move(sf::Vector2f target);
  void write(std::ofstream &output);
};
