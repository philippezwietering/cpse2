#include <exception>
#include <string>

class no_such_file : public std::exception {
private:
  std::string msg;

public:
  no_such_file(const std::string &filename) {
    msg = "No such file " + filename + "\n";
  }
  const char *what() const _GLIBCXX_USE_NOEXCEPT override {
    return msg.c_str();
  }
};

class end_of_file : public std::exception {
private:
  std::string msg;

public:
  end_of_file() { msg = "End of file reached.\n"; }
  const char *what() const _GLIBCXX_USE_NOEXCEPT { return msg.c_str(); }
};

class unknown_drawable : public std::exception {
private:
  std::string msg;

public:
  unknown_drawable(const std::string &name) {
    msg = "Unkown drawable " + name + "\n";
  }
  const char *what() const _GLIBCXX_USE_NOEXCEPT { return msg.c_str(); }
};

class unknown_color : public std::exception {
private:
  std::string msg;

public:
  unknown_color(const std::string &color) {
    msg = "Unkown color " + color + "\n";
  }
  const char *what() const _GLIBCXX_USE_NOEXCEPT { return msg.c_str(); }
};

class invalid_position : public std::exception {
private:
  std::string msg;

public:
  invalid_position(const char &c) {
    msg = "Invalid position of character " + std::to_string(c) + "\n";
  }
  const char *what() const _GLIBCXX_USE_NOEXCEPT { return msg.c_str(); }
};

class invalid_character : public std::exception {
private:
  std::string msg;

public:
  invalid_character(const char &c) {
    msg = "Invalid character " + std::to_string(c) + "\n";
  }
  const char *what() const _GLIBCXX_USE_NOEXCEPT { return msg.c_str(); }
};
