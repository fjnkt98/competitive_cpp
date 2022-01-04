#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t A, B, C, K;
  std::cin >> A >> B >> C >> K;

  int64_t answer = 0;
  if (K % 2 == 0) {
    answer = A - B;
  } else {
    answer = B - A;
  }

  if (answer > 1e18) {
    std::cout << "Unfair" << std::endl;
  } else {
    std::cout << answer << std::endl;
  }

  return 0;
}