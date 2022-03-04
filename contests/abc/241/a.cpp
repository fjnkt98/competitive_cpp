#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<int64_t> a(10);
  for (int64_t i = 0; i < 10; i++) {
    std::cin >> a.at(i);
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < 3; i++) {
    answer = a.at(answer);
  }

  std::cout << answer << std::endl;

  return 0;
}
