#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<std::vector<int64_t>> P(N, std::vector<int64_t>(3));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < 3; j++) {
      std::cin >> P.at(i).at(j);
    }
  }

  std::vector<int64_t> point(N);
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < 3; j++) {
      point.at(i) += P.at(i).at(j);
    }
  }

  std::vector<int64_t> order(N);
  std::copy(point.begin(), point.end(), order.begin());

  std::sort(order.begin(), order.end());

  std::vector<bool> possible(N, true);
  for (int64_t i = 0; i < N; i++) {
    auto iter = std::upper_bound(order.begin(), order.end(), point.at(i) + 300);
    int64_t distance = std::distance(iter, order.end());

    if (distance >= K) {
      possible.at(i) = false;
    }
  }

  for (int64_t i = 0; i < N; i++) {
    if (possible.at(i)) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

  return 0;
}
