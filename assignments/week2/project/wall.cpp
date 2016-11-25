#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size)
    : position(position), size(size) {}

void wall::draw(sf::RenderWindow &window) const {
  sf::RectangleShape rectangle;
  rectangle.setPosition(position);
  rectangle.setSize(size);
  window.draw(rectangle);
}
