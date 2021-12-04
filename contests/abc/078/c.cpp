#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  int64_t time = 1900 * M + 100 * (N - M);
  int64_t p = 1;
  for (int64_t i = 0; i < M; i++) {
    p *= 2;
  }

  std::cout << time * p << std::endl;

  return 0;
}
