#pragma once

#include <SFML/Graphics.hpp>

class ball : public drawable {
private:
  sf::Vector2f position;
  float size;

public:
  ball(sf::Vector2f position, float size);
  void draw() const;
};
