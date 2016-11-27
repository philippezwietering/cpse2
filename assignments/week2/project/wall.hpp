#pragma once

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class wall : public drawable {
private:
  sf::RectangleShape rectangle;

public:
  wall(sf::Vector2f position, sf::Vector2f size);
  void draw(sf::RenderWindow &window) const;
  void updatePosition();
  sf::FloatRect getBounds() const;
};
