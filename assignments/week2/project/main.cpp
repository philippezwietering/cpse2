#include "action.hpp"
#include "ball.hpp"
#include "block.hpp"
#include "wall.hpp"
#include <iostream>

sf::Vector2f Vector2fFromVector2i(sf::Vector2i rhs) {
  return sf::Vector2f(static_cast<float>(rhs.x), static_cast<float>(rhs.y));
}

int main() {
  sf::RenderWindow window{sf::VideoMode{1000, 720}, "SFML Window"};
  ball testBall{sf::Vector2f{320.0, 240.0}};
  wall upperWall{sf::Vector2f{0.0, 0.0}, sf::Vector2f{990.0, 10.0}};
  wall *puw = &upperWall;
  wall rightWall{sf::Vector2f{990.0, 0.0}, sf::Vector2f{1000.0, 710.0}};
  wall *prw = &rightWall;
  wall lowerWall{sf::Vector2f{10.0, 710.0}, sf::Vector2f{1000.0, 720.0}};
  wall *plw = &lowerWall;
  wall leftWall{sf::Vector2f{0.0, 10.0}, sf::Vector2f{10.0, 720.0}};
  wall *pew = &leftWall;
  block testBlock{sf::Vector2f{500.0, 500.0}, sf::Vector2f{200.0, 200.0}};
  block *ptb = &testBlock;

  drawable *objectList[] = {puw, prw, plw, pew, ptb};

  action actions[] = {
      action(sf::Keyboard::Left,
             [&] { testBall.move(sf::Vector2f(-1.0, 0.0)); }),
      action(sf::Keyboard::Right,
             [&] { testBall.move(sf::Vector2f(1.0, 0.0)); }),
      action(sf::Keyboard::Up, [&] { testBall.move(sf::Vector2f(0.0, -1.0)); }),
      action(sf::Keyboard::Down,
             [&] { testBall.move(sf::Vector2f(0.0, 1.0)); }),
      action(sf::Mouse::Left,
             [&] {
               testBall.jump(
                   Vector2fFromVector2i(sf::Mouse::getPosition(window)));
             }),
      action(sf::Mouse::Right,
             [&] {
               testBlock.jump(
                   Vector2fFromVector2i(sf::Mouse::getPosition(window)));
             }),
      action([&] {
        auto fx =
            sf::FloatRect(testBall.getBounds().left + testBall.getVelocity().x,
                          testBall.getBounds().top, testBall.getBounds().width,
                          testBall.getBounds().height);
        auto fy = sf::FloatRect(
            testBall.getBounds().left,
            testBall.getBounds().top + testBall.getVelocity().y,
            testBall.getBounds().width, testBall.getBounds().height);

        for (auto &object : objectList) {
          if (fx.intersects(object->getBounds())) {
            testBall.bounce(1.0);
          }
          if (fy.intersects(object->getBounds())) {
            testBall.bounce(-1.0);
          }
        }
      }),
      action([&] { testBall.updatePosition(); })};

  window.clear();
  testBall.draw(window);
  upperWall.draw(window);
  rightWall.draw(window);
  lowerWall.draw(window);
  leftWall.draw(window);
  testBlock.draw(window);
  window.display();

  while (window.isOpen()) {
    for (auto &action : actions) {
      action();
    }

    window.clear();
    testBall.draw(window);
    upperWall.draw(window);
    rightWall.draw(window);
    lowerWall.draw(window);
    leftWall.draw(window);
    testBlock.draw(window);
    window.display();

    sf::sleep(sf::milliseconds(20));

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }
  std::cout << "Terminating application\n";
  return 0;
}
