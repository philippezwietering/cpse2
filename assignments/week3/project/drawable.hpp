#pragma once

#include <SFML/Graphics.hpp>
class drawable {
public:
  virtual void draw(sf::RenderWindow &window) const = 0;
  virtual sf::FloatRect getBounds() const = 0;
  virtual void move(sf::Vector2f target) = 0;
  virtual void setMoveable(bool m) = 0;
  virtual bool isMoveable() const = 0;
};
