#include "ball.hpp"

// sf::Vector2f Vector2fFromVector2i(sf::Vector2i rhs) {
//   return sf::Vector2f(static_cast<float>(rhs.x), static_cast<float>(rhs.y));
// }

int main() {
  sf::RenderWindow window{sf::VideoMode{640, 480}, "SFML Window"};
  ball testBall{sf::Vector2f{320.0, 240.0}};

  window.clear();
  testBall.draw(window);
  window.display();

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    sf::sleep(sf::milliseconds(20));
  }
  return 0;
}
