#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t L, N;
  std::cin >> L >> N;
  std::vector<int64_t> x(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> x.at(i);
  }

  int64_t min_time = 0;
  for (int64_t i = 0; i < N; i++) {
    min_time = std::max(min_time, std::min(x.at(i), L - x.at(i)));
  }

  int64_t max_time = 0;
  for (int64_t i = 0; i < N; i++) {
    max_time = std::max(max_time, std::max(x.at(i), L - x.at(i)));
  }

  std::cout << min_time << " " << max_time << std::endl;

  return 0;
}
