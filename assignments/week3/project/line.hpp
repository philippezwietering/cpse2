#pragma once

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class line : public drawable {
private:
  sf::VertexArray l;

public:
  line(sf::Vector2f start, sf::Vector2f end, sf::Color color);
  void draw(sf::RenderWindow &window) const;
  sf::FloatRect getBounds() const;
  void move(sf::Vector2f target);
  void write(std::ofstream &output);
};
