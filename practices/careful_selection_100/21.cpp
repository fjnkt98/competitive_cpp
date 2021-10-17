/*
 * https://atcoder.jp/contests/abc023/tasks/abc023_d
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> H(N);
  std::vector<int64_t> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> H.at(i) >> S.at(i);
  }

  int64_t right = 0;
  for (int64_t i = 0; i < N; i++) {
    right = std::max(right, H.at(i) + S.at(i) * N);
  }
  int64_t left = 0;

  while (right - left > 1) {
    int64_t mid = (right + left) / 2;

    bool ok = true;

    std::vector<int64_t> time_limit(N, 0);
    for (int64_t i = 0; i < N; i++) {
      if (mid < H.at(i)) {
        ok = false;
      } else {
        time_limit.at(i) = (mid - H.at(i)) / S.at(i);
      }
    }

    std::sort(time_limit.begin(), time_limit.end());
    for (int64_t i = 0; i < N; i++) {
      if (time_limit.at(i) < i) {
        ok = false;
      }
    }

    if (ok) right = mid;
    else left = mid;
  }

  std::cout << right << std::endl;

  return 0;

}
