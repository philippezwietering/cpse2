#include "ball.hpp"
#include <iostream>

ball::ball(sf::Vector2f position, float size)
    : circle(), velocity(sf::Vector2f{0.0, 0.0}) {
  circle.setRadius(size);
  circle.setPosition(position);
}

void ball::draw(sf::RenderWindow &window) const { window.draw(circle); }

void ball::move(sf::Vector2f difference) { velocity += difference; }

void ball::jump(sf::Vector2f target) {
  circle.setPosition(sf::Vector2f{target.x - circle.getRadius(),
                                  target.y - circle.getRadius()});
}

void ball::bounce(float direction) {
  velocity = sf::Vector2f{direction * velocity.x, -direction * velocity.y};
}
void ball::updatePosition() { circle.move(velocity); }

sf::FloatRect ball::getBounds() const { return circle.getGlobalBounds(); }
