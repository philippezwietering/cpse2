#include "picture.hpp"
#include "exception.hpp"
#include <fstream>
#include <iostream>

picture::picture(sf::Vector2f position, std::string filename)
    : pic(), tex(), filename(filename) {
  if (!tex.loadFromFile(filename)) {
    throw no_such_file(filename);
  } else {
    tex.setSmooth(true);
    tex.setRepeated(false);

    pic.setTexture(tex);
    pic.setPosition(position);
    pic.setColor(sf::Color::Magenta);
  }
}

void picture::draw(sf::RenderWindow &window) const { window.draw(pic); }

void picture::move(sf::Vector2f target) { pic.move(target); }

sf::FloatRect picture::getBounds() const { return pic.getGlobalBounds(); }

void picture::write(std::ofstream &output) {
  output << "(";
  output << pic.getPosition().x;
  output << ",";
  output << pic.getPosition().y;
  output << ") PICTURE ";
  output << filename;
  output << "\n";
}
