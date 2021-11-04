#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;

  int64_t residue = N % K;

  std::cout << std::min(residue, std::abs(residue - K)) << std::endl;

  return 0;
}
