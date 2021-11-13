#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K, A;
  std::cin >> N >> K >> A;

  int64_t target = A;
  for (int64_t i = 0; i < K - 1; i++) {
    target++;
    if (target > N) {
      target = 1;
    }
  }
  std::cout << target << std::endl;

  return 0;
}
