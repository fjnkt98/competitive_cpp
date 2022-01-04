#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t D, N;
  std::cin >> D >> N;

  if (N == 100) N++;
  std::cout << N;
  for (int64_t i = 0; i < D; i++) {
    std::cout << "00";
  }
  std::cout << std::endl;

  return 0;
}
