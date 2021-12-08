#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M, K;
  std::cin >> N >> M >> K;

  if (N == 1 || M == 1) {
    std::cout << "Yes" << std::endl;
    return 0;
  }

  bool ok = false;
  for (int64_t i = 0; i <= N; i++) {
    for (int64_t j = 0; j <= M; j++) {
      int64_t black = i * (M - j) + j * (N - i);

      if (black == K) ok = true;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
