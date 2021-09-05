#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t count = 0;
  for (int64_t i = 1; i <= N; i++) {
    int64_t x = std::stol(std::to_string(i) + std::to_string(i));
    if (x <= N) {
      count++;
    } else {
      break;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
