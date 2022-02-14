#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  std::string S;
  std::cin >> S;

  int64_t N = static_cast<int64_t>(S.size()) + 1;

  std::vector<int64_t> count(N);
  for (int64_t i = 0; i < N - 1; i++) {
    if (S.at(i) == '<') {
      count.at(i + 1) = std::max(count.at(i + 1), count.at(i) + 1);
    }
  }

  for (int64_t i = N - 2; i >= 0; i--) {
    if (S.at(i) == '>') {
      count.at(i) = std::max(count.at(i), count.at(i + 1) + 1);
    }
  }

  std::cout << std::accumulate(count.begin(), count.end(), 0LL) << std::endl;

  return 0;
}