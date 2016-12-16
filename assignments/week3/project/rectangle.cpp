#include "rectangle.hpp"
#include "color.hpp"
#include <fstream>
#include <iostream>

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : rect() {
  rect.setPosition(position);
  rect.setSize(size);
  rect.setFillColor(color);
}

void rectangle::draw(sf::RenderWindow &window) const { window.draw(rect); }

sf::FloatRect rectangle::getBounds() const { return rect.getGlobalBounds(); }

void rectangle::move(sf::Vector2f target) { rect.move(target); }

void rectangle::write(std::ofstream &output) {
  output << "(";
  output << rect.getPosition().x;
  output << ",";
  output << rect.getPosition().y;
  output << ") RECTANGLE ";
  for (auto const &color : colors) {
    if (color.color == rect.getFillColor()) {
      output << color.name;
      break;
    }
  }
  output << " ";
  output << "(";
  output << rect.getSize().x;
  output << ",";
  output << rect.getSize().y;
  output << ")\n";
}
