#include "line.hpp"

line::line(sf::Vector2f start, sf::Vector2f end, sf::Color color)
    : l(sf::Lines, 2), moveable(false) {
  l[0].position = start;
  l[1].position = end;

  l[0].color = color;
  l[1].color = color;
}

void line::draw(sf::RenderWindow &window) const { window.draw(l); }

void line::move(sf::Vector2f target) {
  l[0].position += target;
  l[1].position += target;
}

sf::FloatRect line::getBounds() const { return l.getBounds(); }

void line::setMoveable(bool m) { moveable = m; }

bool line::isMoveable() const { return moveable; }
