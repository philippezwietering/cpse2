#include "picture.hpp"

picture::picture(const int &xId, const int &yId, const sf::Vector2f &position, const std::string &filename)
    : sprite(), tex(), filename(filename), xId(xId), yId(yId) {
  tex.loadFromFile(filename);
  tex.setSmooth(true);
  tex.setRepeated(true);

  sprite.setTexture(tex);
  sprite.setPosition(position);
}

void picture::draw(sf::RenderWindow &window) const { window.draw(sprite); }

sf::FloatRect picture::getBounds() const { return sprite.getGlobalBounds(); }
