#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string input;
  std::cin >> input;

  std::string X, Y;
  auto iter = std::find(input.begin(), input.end(), '.');
  for (auto i = input.begin(); i != iter; i++) {
    X.push_back(*i);
  }
  for (auto i = iter + 1; i != input.end(); i++) {
    Y.push_back(*i);
  }

  int64_t x = std::stoi(X);
  int64_t y = std::stoi(Y);
  if (y >= 0 && y <= 2) std::cout << x << "-" << std::endl;
  else if (y >= 3 && y <= 6) std::cout << x << std::endl;
  else std::cout << x << "+" << std::endl;

  return 0;
}
