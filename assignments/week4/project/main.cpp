#include "exception.hpp"
#include <algorithm>
#include <array>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <string>
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

struct charFrequency {
  int frequency;
  char c;
};
struct stringFrequency {
  int frequency;
  std::string s;
};

bool sortFrequency(charFrequency i, charFrequency j) {
  return i.frequency > j.frequency;
}
bool sortWordFrequency(stringFrequency i, stringFrequency j) {
  return i.frequency > j.frequency;
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

  std::array<charFrequency, 26> frequencyArray;
  int iter = 0;
  for (auto i : charArray) {
    frequencyArray[iter].c = 'a' + iter;
    frequencyArray[iter].frequency = i;
    iter++;
  }
  std::cout << "\nNow sorted on frequency:\n";
  std::sort(frequencyArray.begin(), frequencyArray.end(), sortFrequency);
  for (auto a : frequencyArray) {
    std::cout << char(a.c) << ": " << a.frequency << "\n";
  }

  std::map<std::string, int> wordMap;
  auto word = std::string();

  for (int i = 0; i < charVector.size(); i++) {
    if (isalpha(charVector[i])) {
      word = char(charVector[i]);
      i++;
      while (isalpha(charVector[i])) {
        word.push_back(char(charVector[i]));
        i++;
      }
      if (wordMap.find(word) != wordMap.end()) {
        (wordMap.find(word)->second)++;
      } else {
        wordMap[word] = 1;
      }
    }
  }

  std::vector<stringFrequency> wordVector;
  for (auto a : wordMap) {
    wordVector.push_back(stringFrequency{a.second, a.first});
  }
  std::sort(wordVector.begin(), wordVector.end(), sortWordFrequency);
  std::cout << "\nWords:\n";
  for (auto a : wordVector) {
    std::cout << a.s << ": " << a.frequency << "\n";
  }

  // for (auto a : charVector) {
  //   std::cout << a;
  // }

  return 0;
}
