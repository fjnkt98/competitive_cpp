#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;

  int64_t sum = 0;
  for (int64_t n = 1; n <= N; n++) {
    for (int64_t k = 1; k <= K; k++) {
      sum += n * 100 + k;
    }
  }

  std::cout << sum << std::endl;

  return 0;
}
