#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t A, N;
  std::cin >> A >> N;

  std::cout << (A | (1 << N)) << std::endl;

  return 0;
}