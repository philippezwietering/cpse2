#include "circle.hpp"
#include "color.hpp"
#include <fstream>
#include <iostream>

circle::circle(sf::Vector2f position, sf::Color color, float size) : c() {
  c.setRadius(size);
  c.setPosition(position);
  c.setFillColor(color);
}

void circle::draw(sf::RenderWindow &window) const { window.draw(c); }

void circle::move(sf::Vector2f target) { c.move(target); }

sf::FloatRect circle::getBounds() const { return c.getGlobalBounds(); }

void circle::write(std::ofstream &output) {
  output << "(";
  output << c.getPosition().x;
  output << ",";
  output << c.getPosition().y;
  output << ") CIRCLE ";
  for (auto const &color : colors) {
    if (color.color == c.getFillColor()) {
      output << color.name;
      break;
    }
  }
  output << " ";
  output << c.getRadius();
  output << "\n";
}
