/*
 * AtCoder Educational DP Contest C - Vacation.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

template <class T> void choose_max(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> a(N);
  std::vector<int64_t> b(N);
  std::vector<int64_t> c(N);

  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i) >> b.at(i) >> c.at(i);
  }

  // DP table
  // dp.at(i).at(0) => "swim in the sea at i-th day"
  // dp.at(i).at(1) => "insect catching at i-th day"
  // dp.at(i).at(2) => "do homework at i-th day"
  std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(3, 0));

  // DP loop
  for (int64_t i = 1; i <= N; i++) {
    // When Taro swim in the sea
    choose_max(dp.at(i).at(0), dp.at(i - 1).at(1) + a.at(i - 1));
    choose_max(dp.at(i).at(0), dp.at(i - 1).at(2) + a.at(i - 1));

    // When Taro catch insect
    choose_max(dp.at(i).at(1), dp.at(i - 1).at(0) + b.at(i - 1));
    choose_max(dp.at(i).at(1), dp.at(i - 1).at(2) + b.at(i - 1));

    // When Taro do homework
    choose_max(dp.at(i).at(2), dp.at(i - 1).at(0) + c.at(i - 1));
    choose_max(dp.at(i).at(2), dp.at(i - 1).at(1) + c.at(i - 1));
  }

  int64_t answer = 0;
  answer = std::max(
      dp.at(N).at(0),
      std::max(
        dp.at(N).at(1),
        dp.at(N).at(2)
        )
      );

  std::cout << answer << std::endl;

  return 0;
}
