#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size) : rectangle() {
  rectangle.setPosition(position);
  rectangle.setSize(size);
  rectangle.setFillColor(sf::Color::Blue);
}

void wall::draw(sf::RenderWindow &window) const { window.draw(rectangle); }

void wall::updatePosition() {}

sf::FloatRect wall::getBounds() const { return rectangle.getGlobalBounds(); }
