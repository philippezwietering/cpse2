#include <exception>
#include <string>

class no_such_file : public std::exception {
private:
  std::string msg;

public:
  no_such_file(const char *filename, int line) {
    msg =
        "No such file at " + std::string(filename) + ":" + std::to_string(line);
  }
  const char *what() { return msg.c_str(); }
};

class end_of_file : public std::exception {
private:
  std::string msg;

public:
  end_of_file() { msg = "End of file reached."; }
  const char *what() { return msg.c_str(); }
};

class unknown_drawable : public std::exception {
private:
  std::string msg;

public:
  unknown_drawable(const std::string &name) { msg = "Unkown drawable " + name; }
  const char *what() { return msg.c_str(); }
};

class unknown_color : public std::exception {
private:
  std::string msg;

public:
  unknown_color(const std::string &color) { msg = "Unkown color " + color; }
  const char *what() { return msg.c_str(); }
};

class invalid_position : public std::exception {
private:
  std::string msg;

public:
  invalid_position(const char &c) {
    msg = "Invalid position of character " + std::to_string(c);
  }
  const char *what() { return msg.c_str(); }
};

class invalid_character : public std::exception {
private:
  std::string msg;

public:
  invalid_character(const char &c) {
    msg = "Invalid character " + std::to_string(c);
  }
  const char *what() { return msg.c_str(); }
};
