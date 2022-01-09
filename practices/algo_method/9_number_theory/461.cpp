#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  int64_t A, B, N;
  std::cin >> A >> B >> N;

  std::cout << N / (B / std::gcd(A, B)) << std::endl;

  return 0;
}