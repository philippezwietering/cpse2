#include "circle.hpp"
#include <iostream>

circle::circle(sf::Vector2f position, sf::Color color, float size)
    : c(), moveable(false) {
  c.setRadius(size);
  c.setPosition(position);
  c.setFillColor(color);
}

void circle::draw(sf::RenderWindow &window) const { window.draw(c); }

void circle::move(sf::Vector2f target) { c.move(target); }

sf::FloatRect circle::getBounds() const { return c.getGlobalBounds(); }

void circle::setMoveable(bool m) { moveable = m; }

bool circle::isMoveable() const { return moveable; }
