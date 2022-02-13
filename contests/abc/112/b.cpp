#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, T;
  std::cin >> N >> T;
  std::vector<std::pair<int64_t, int64_t>> input(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t c, t;
    std::cin >> c >> t;

    input.at(i) = std::make_pair(c, t);
  }

  bool ok = false;
  for (int64_t i = 0; i < N; i++) {
    auto [c, t] = input.at(i);

    if (t <= T) {
      ok = true;
    }
  }

  if (ok) {
    int64_t answer = 0;
    int64_t cost = 1LL << 60;
    for (int64_t i = 0; i < N; i++) {
      auto [c, t] = input.at(i);

      if (t > T) continue;

      if (cost > c) {
        cost = c;
        answer = i + 1;
      }
    }

    std::cout << cost << std::endl;

  } else {
    std::cout << "TLE" << std::endl;
  }

  return 0;
}