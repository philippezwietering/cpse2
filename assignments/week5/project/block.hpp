#ifndef BLOCK
#define BLOCK

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class block : public drawable{
private:
  sf::RectangleShape rect;

public:
  int xId, yId;
  block(const int &xId, const int &yId, const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color);
  void draw(sf::RenderWindow &window) const;
  sf::FloatRect getBounds() const;
};


#endif /* end of include guard: BLOCK.HPP */
