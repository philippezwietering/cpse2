#include "picture.hpp"
#include "exception.hpp"

picture::picture(sf::Vector2f position, std::string filename)
    : pic(), tex(), moveable(false) {
  if (!tex.loadFromFile(filename)) {
    throw no_such_file(__FILE__, __LINE__);
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

void picture::setMoveable(bool m) { moveable = m; }

bool picture::isMoveable() const { return moveable; }
