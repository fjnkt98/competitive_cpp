#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> X(N);
  std::vector<int64_t> L(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i) >> L.at(i);
  }

  std::vector<std::pair<int64_t, int64_t>> range(N);
  for (int64_t i = 0; i < N; i++) {
    range.at(i).first = X.at(i) + L.at(i);
    range.at(i).second = X.at(i) - L.at(i);
  }

  std::sort(range.begin(), range.end());

  int64_t answer = 0;
  int64_t current_endpoint = -(1LL << 60);
  for (int64_t i = 0; i < N; i++) {
    if (range.at(i).second < current_endpoint) {
      continue;
    }

    answer++;
    current_endpoint = range.at(i).first;
  }

  std::cout << answer << std::endl;

  return 0;
}
