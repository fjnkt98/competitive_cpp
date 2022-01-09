#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  int64_t A, B, K;
  std::cin >> A >> B >> K;

  int64_t lcm = std::lcm(A, B);

  std::cout << lcm * K << std::endl;

  return 0;
}