#ifndef PICTURE
#define PICTURE

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class picture : public drawable {
private:
  sf::Sprite sprite;
  sf::Texture tex;
  std::string filename;

public:
  int xId, yId;
  picture(const int &xId, const int &yId, const sf::Vector2f &position, const std::string &filename);
  void draw(sf::RenderWindow &window) const;
  sf::FloatRect getBounds() const;
};

#endif /* end of include guard: PICTURE.HPP */
