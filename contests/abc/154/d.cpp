#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> p(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> p.at(i);
  }

  int64_t left = 0;
  int64_t right = K - 1;
  double expected = 0.0;
  for (int64_t i = left; i <= right; i++) {
    expected += static_cast<double>(p.at(i) * (p.at(i) + 1)) / (2 * p.at(i));
  }

  double answer = expected;
  while (right < N - 1) {
    right++;

    expected += static_cast<double>(p.at(right) * (p.at(right) + 1)) / (2 * p.at(right));
    expected -= static_cast<double>(p.at(left) * (p.at(left) + 1)) / (2 * p.at(left));

    answer = std::max(answer, expected);

    left++;
  }

  std::cout << std::fixed << std::setprecision(10) << answer << std::endl;

  return 0;
}
