#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : rect(), moveable(false) {
  rect.setPosition(position);
  rect.setSize(size);
  rect.setFillColor(color);
}

void rectangle::draw(sf::RenderWindow &window) const { window.draw(rect); }

sf::FloatRect rectangle::getBounds() const { return rect.getGlobalBounds(); }

void rectangle::move(sf::Vector2f target) { rect.move(target); }
void rectangle::setMoveable(bool m) { moveable = m; }

bool rectangle::isMoveable() const { return moveable; }
