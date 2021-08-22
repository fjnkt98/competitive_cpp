#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::cout << (N - 1) / 100 + 1 << std::endl;

  return 0;
}
