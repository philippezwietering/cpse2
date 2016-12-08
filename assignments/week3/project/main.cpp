#include "action.hpp"
#include "circle.hpp"
#include "exception.hpp"
#include "line.hpp"
#include "picture.hpp"
#include "rectangle.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <list>

sf::Vector2f Vector2fFromVector2i(sf::Vector2i rhs) {
  return sf::Vector2f(static_cast<float>(rhs.x), static_cast<float>(rhs.y));
}

std::ifstream &operator>>(std::ifstream &input, sf::Vector2f &rhs) {
  char c;
  if (!(input >> c)) {
    throw end_of_file();
  }
  if (c != '(') {
    throw invalid_position(c);
  }
  if (!(input >> rhs.x)) {
    throw invalid_character(c);
  }
  if (!(input >> c) && c != ',') {
    throw invalid_position(c);
  }
  if (!(input >> rhs.y)) {
    throw invalid_character(c);
  }
  if (!(input >> c) && c != ')') {
    throw invalid_position(c);
  }
  return input;
}

std::ifstream &operator>>(std::ifstream &input, sf::Color &rhs) {
  std::string s;
  input >> s;
  const struct {
    const char *name;
    sf::Color color;
  } colors[]{{"yellow", sf::Color::Yellow}, {"red", sf::Color::Red},
             {"blue", sf::Color::Blue},     {"green", sf::Color::Green},
             {"black", sf::Color::Black},   {"cyan", sf::Color::Cyan},
             {"white", sf::Color::White}};
  for (auto const &color : colors) {
    if (color.name == s) {
      rhs = color.color;
      return input;
    }
  }
  if (s == "") {
    throw end_of_file();
  } else {
    throw unknown_color(s);
  }
}

drawable *read_drawable(std::ifstream &input) {
  sf::Vector2f position;
  std::string name;
  input >> position >> name;

  if (name == "CIRCLE") {
    sf::Color c;
    int radius;
    input >> c >> radius;
    return new circle(position, c, radius);
  } else if (name == "RECTANGLE") {
    sf::Color c;
    sf::Vector2f size;
    input >> c >> size;
    return new rectangle(position, size, c);
  } else if (name == "LINE") {
    sf::Color c;
    sf::Vector2f end;
    input >> c >> end;
    return new line(position, end, c);
  } else if (name == "PICTURE") {
    std::string filename;
    input >> filename;
    return new picture(position, filename);
  } else if (name == "") {
    throw end_of_file();
  } else {
    throw unknown_drawable(name);
  }
}

int main() {
  sf::RenderWindow window{sf::VideoMode{1000, 720}, "SFML Window"};
  std::ifstream input("project/objects.txt");
  std::list<drawable *> drawables;
  try {
    while (true) {
      drawables.push_back(read_drawable(input));
    }
  } catch (end_of_file) {
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  drawable *moveableDrawable = nullptr;
  action actions[] = {
      action(sf::Keyboard::Left,
             [&] { moveableDrawable->move(sf::Vector2f(-1.0, 0.0)); }),
      action(sf::Keyboard::Right,
             [&] { moveableDrawable->move(sf::Vector2f(1.0, 0.0)); }),
      action(sf::Keyboard::Up,
             [&] { moveableDrawable->move(sf::Vector2f(0.0, -1.0)); }),
      action(sf::Keyboard::Down,
             [&] { moveableDrawable->move(sf::Vector2f(0.0, 1.0)); })};
  while (window.isOpen()) {

    for (auto &action : actions) {
      if (moveableDrawable) {
        action();
      }
    }
    window.clear();
    for (auto d : drawables) {
      d->draw(window);
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
          d->getBounds().contains(
              Vector2fFromVector2i(sf::Mouse::getPosition(window)))) {
        moveableDrawable = d;
      }
    }
    window.display();
    sf::sleep(sf::milliseconds(20));

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }
}
