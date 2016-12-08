#pragma once

#include "drawable.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class picture : public drawable {
private:
  sf::Sprite pic;
  sf::Texture tex;
  bool moveable;

public:
  picture(sf::Vector2f position, std::string filename);
  void draw(sf::RenderWindow &window) const;
  void move(sf::Vector2f target);
  sf::FloatRect getBounds() const;
  void setMoveable(bool m);
  bool isMoveable() const;
};
