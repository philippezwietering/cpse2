#include "block.hpp"

block::block(sf::Vector2f position, sf::Vector2f size) : rectangle() {
  rectangle.setPosition(position);
  rectangle.setSize(size);
  rectangle.setFillColor(sf::Color::Green);
}

void block::draw(sf::RenderWindow &window) const { window.draw(rectangle); }

void block::updatePosition() {}

sf::FloatRect block::getBounds() const { return rectangle.getGlobalBounds(); }

void block::jump(sf::Vector2f target) {
  rectangle.setPosition(target - sf::Vector2f{rectangle.getSize().x / 2.0,
                                              rectangle.getSize().y / 2.0});
}
