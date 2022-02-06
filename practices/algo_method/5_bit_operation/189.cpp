#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;

  std::cout << (1 << N) << std::endl;

  return 0;
}