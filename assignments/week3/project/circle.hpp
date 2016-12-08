#pragma once

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class circle : public drawable {
private:
  sf::CircleShape c;
  bool moveable;

public:
  circle(sf::Vector2f position, sf::Color color, float size = 30.0);
  void draw(sf::RenderWindow &window) const;
  void move(sf::Vector2f target);
  sf::FloatRect getBounds() const;
  void setMoveable(bool m);
  bool isMoveable() const;
};
