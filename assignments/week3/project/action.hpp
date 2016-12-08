#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

class action {
private:
  std::function<bool()> condition;
  std::function<void()> work;

public:
  action(std::function<bool()> condition, std::function<void()> work)
      : condition(condition), work(work) {}

  action(sf::Keyboard::Key key, std::function<void()> work)
      : condition([key]() -> bool { return sf::Keyboard::isKeyPressed(key); }),
        work(work) {}

  action(sf::Mouse::Button button, std::function<void()> work)
      : condition(
            [button]() -> bool { return sf::Mouse::isButtonPressed(button); }),
        work(work) {}

  action(std::function<void()> work)
      : condition([]() -> bool { return true; }), work(work) {}

  void operator()() {
    if (condition()) {
      work();
    }
  }
};
