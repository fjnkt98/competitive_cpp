#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> cumsum(N + 1);
  for (int64_t i = 0; i < N; i++) {
    cumsum.at(i + 1) = cumsum.at(i) + A.at(i);
  }

  std::map<int64_t, int64_t> count;
  for (int64_t i = 0; i <= N; i++) {
    count[cumsum.at(i)] += 1;
  }

  int64_t answer = 0;
  for (auto c : count) {
    auto [k, v] = c;

    answer += v * (v - 1) / 2;
  }

  std::cout << answer << std::endl;

  return 0;
}