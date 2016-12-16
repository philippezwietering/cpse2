#include <exception>
#include <string>

template <typename T> class element_not_found : public std::exception {
private:
  std::string s;

public:
  element_not_found(const T &element)
      : s{std::string{"element not found ["} + element + "]"} {}
  const char *what() const override { return s.c_str(); }
};
