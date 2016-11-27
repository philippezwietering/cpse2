#pragma once

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class ball : public drawable {
private:
  sf::Vector2f position;
  float size;

public:
  ball(sf::Vector2f position, float size = 30.0);
  void draw(sf::RenderWindow &window) const;
  void move(sf::Vector2f difference);
  void jump(sf::Vector2f target);
  // void updatePosition();
};
