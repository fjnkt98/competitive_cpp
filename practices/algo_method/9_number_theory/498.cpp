#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  int64_t A, B, K;
  std::cin >> A >> B >> K;

  if (std::max(A, B) < K) {
    std::cout << "No" << std::endl;
    return 0;
  }

  if (K % std::gcd(A, B) == 0) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}