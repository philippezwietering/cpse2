#include "block.hpp"


block::block(const int &xId, const int &yId, const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color & color) : rect(), xId(yId), yId(xId) {
  rect.setPosition(position);
  rect.setSize(size);
  rect.setFillColor(color);
}

void block::draw(sf::RenderWindow &window) const { window.draw(rect); }

sf::FloatRect block::getBounds() const { return rect.getGlobalBounds(); }
