#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, K;
  std::cin >> A >> B >> K;

  if (A < K) {
    B = std::max(static_cast<int64_t>(0), B - (K - A));
    A = 0;
  } else {
    A -= K;
  }

  std::cout << A << " " << B << std::endl;

  return 0;
}
