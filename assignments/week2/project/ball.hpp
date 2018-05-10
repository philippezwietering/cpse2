#pragma once

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class ball : public drawable {
private:
  sf::CircleShape circle;
  sf::Vector2f velocity;

public:
  ball(sf::Vector2f position, float size = 30.0);
  void draw(sf::RenderWindow &window) const;
  void move(sf::Vector2f difference);
  void bounce(float direction);
  void jump(sf::Vector2f target);
  sf::FloatRect getBounds() const;
  void updatePosition();
  sf::Vector2f getVelocity() const;
};
