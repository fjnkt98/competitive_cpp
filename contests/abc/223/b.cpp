#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string shift(std::string S) {
  char first = S.at(0);
  for (size_t i = 1; i < S.size(); i++) {
    S.at(i - 1) = S.at(i);
  }
  S.at(S.size() - 1) = first;

  return S;
}

int main() {
  std::string S;
  std::cin >> S;

  std::string biggest = S;
  std::string smallest = S;
  for (size_t i = 0; i < S.size(); i++) {
    S = shift(S);

    if (smallest > S) {
      smallest = S;
    }
    if (biggest < S) {
      biggest = S;
    }
  }

  std::cout << smallest << std::endl;
  std::cout << biggest << std::endl;

  return 0;
}
