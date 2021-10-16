/*
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i);
  }
  int64_t Q;
  std::cin >> Q;
  std::vector<int64_t> T(N);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> T.at(i);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < Q; i++) {
    int64_t right = N - 1;
    int64_t left = -1;

    while (right - left > 1) {
      int64_t mid = (right + left) / 2;

      if (S.at(mid) >= T.at(i)) {
        right = mid;
      } else {
        left = mid;
      }
    }

    if (S.at(right) == T.at(i)) {
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
