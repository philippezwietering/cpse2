#include "ball.hpp"

ball::ball(sf::Vector2f position, float size)
    : position(position), size(size) {}

void ball::draw(sf::RenderWindow &window) const {
  sf::CircleShape circle;
  circle.setRadius(size);
  circle.setPosition(position);
  window.draw(circle);
}

void ball::move(sf::Vector2f difference) { position += difference; }
void ball::jump(sf::Vector2f target) {
  position = sf::Vector2f{target.x - size, target.y - size};
}
// void ball::updatePosition(){
//
// }
