#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>

int64_t score(std::string S) {
  std::vector<int64_t> count(10);
  std::iota(count.begin(), count.end(), 0);
  for (auto c : S) {
    count.at(c - '0') *= 10;
  }
  return std::accumulate(count.begin(), count.end(), static_cast<int64_t>(0));
}

int main() {
  int64_t K;
  std::string S, T;
  std::cin >> K >> S >> T;

  std::vector<int64_t> count(10, K);
  for (auto c : S) {
    if (c != '#') count.at(c - '0')--;
  }
  for (auto c : T) {
    if (c != '#') count.at(c - '0')--;
  }

  int64_t win = 0;
  for (int64_t i = 1; i < 10; i++) {
    for (int64_t j = 1; j < 10; j++) {
      S.back() = static_cast<char>(i + '0');
      T.back() = static_cast<char>(j + '0');
      if (score(S) > score(T)) {
        int64_t add = (i == j) ? 1 : 0;
        win += count.at(i) * (count.at(j) - add);
      }
    }
  }

  double answer = static_cast<double>(win) / ((9 * K - 8) * (9 * K - 9));

  std::cout << std::fixed << std::setprecision(10) << answer << std::endl;

  return 0;
}
