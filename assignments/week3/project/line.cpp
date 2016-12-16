#include "line.hpp"
#include "color.hpp"
#include <fstream>
#include <iostream>

line::line(sf::Vector2f start, sf::Vector2f end, sf::Color color)
    : l(sf::Lines, 2) {
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

void line::write(std::ofstream &output) {
  output << "(";
  output << l[0].position.x;
  output << ",";
  output << l[0].position.y;
  output << ") LINE ";
  for (auto const &color : colors) {
    if (color.color == l[0].color) {
      output << color.name;
      break;
    }
  }
  output << " ";
  output << "(";
  output << l[1].position.x;
  output << ",";
  output << l[1].position.y;
  output << ")\n";
}
