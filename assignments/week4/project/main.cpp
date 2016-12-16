#include "exception.hpp"
#include <algorithm>
#include <array>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

std::vector<char> readCharsFromFile(std::ifstream &input) {
  std::vector<char> result;
  char c;

  if (input.is_open()) {
    while (input.get(c)) {
      result.push_back(c);
    }
  }
  return result;
}

template <typename T> void range_print(T begin, T end) {
  for (T p = begin; p != end; p++) {
    std::cout << *p << "";
  }
  std::cout << "\n";
}

template <typename T, typename E>
void range_apply(T begin, T end, void f(E &)) {
  for (T p = begin; p != end; p++) {
    f(*p);
  }
}

template <typename T, typename V, typename E = element_not_found<V>>
T find_or_throw(T begin, T end, const V &value) {
  T found = find(begin, end, value);
  if (found == end) {
    throw(value);
  }
  return found;
}

int main() {
  std::vector<char> charVector;
  std::ifstream input("bible.txt");
  charVector = readCharsFromFile(input);

  std::cout << "\nThe size of the vector is " << charVector.size() << "\n";

  std::cout << "The amount of lines in the file is "
            << std::count(charVector.begin(), charVector.end(), '\n') << "\n";

  std::cout << "The amount of alphabetic characters in the file is "
            << std::count_if(charVector.begin(), charVector.end(), isalpha)
            << "\n";

  for_each(charVector.begin(), charVector.end(),
           [](char &c) { c = tolower(c); });

  std::array<int, 26> charArray;
  charArray.fill(0);
  for_each(charVector.begin(), charVector.end(), [&charArray](char &c) {
    if (isalpha(c)) {
      charArray[c - 'a']++;
    }
  });

  int alphaCount = 0;
  for (auto a : charArray) {
    std::cout << char('a' + alphaCount) << ": " << a << "\n";
    alphaCount++;
  }

  // for (auto a : charVector) {
  //   std::cout << a;
  // }

  return 0;
}
