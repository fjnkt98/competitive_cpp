#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string O, E;
  std::cin >> O >> E;

  std::string answer = "";
  if (O.size() == E.size()) {
    for (size_t i = 0; i < O.size(); i++) {
      answer.push_back(O.at(i));
      answer.push_back(E.at(i));
    }
  } else {
    for (size_t i = 0; i < E.size(); i++) {
      answer.push_back(O.at(i));
      answer.push_back(E.at(i));
    }
    answer.push_back(O.back());
  }

  std::cout << answer << std::endl;

  return 0;
}
