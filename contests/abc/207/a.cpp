#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<int64_t> input(3);
  for (int64_t i = 0; i < 3; i++) {
    std::cin >> input.at(i);
  }

  std::sort(input.begin(), input.end());

  std::cout << input.at(1) + input.at(2) << std::endl;

  return 0;
}
