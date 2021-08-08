#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> weight(N);
  for (int64_t& w : weight) {
    std::cin >> w;
  }

  int64_t left = 0;
  int64_t right = 1LL << 60;

  while (right - left > 1) {
    int64_t mid = (right + left) / 2;

    bool satisfied = true;

    int64_t truck = 1;
    int64_t load = 0;
    for (int64_t i = 0; i < N; i++) {
      if (mid < weight.at(i)) {
        satisfied = false;
        break;
      }

      if (load + weight.at(i) > mid) {
        truck++;
        load = 0;
      }

      load += weight.at(i);
    }

    if (truck > K || load > mid) {
      satisfied = false;
    }

    if (satisfied) {
      right = mid;
    } else {
      left = mid;
    }
  }

  std::cout << right << std::endl;

  return 0;
}
