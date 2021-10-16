/*
 * https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t answer = 1LL << 60;
  for (int64_t bit; bit < (1 << N); bit++) {
    std::vector<int64_t> B(N);
    std::copy(A.begin(), A.end(), B.begin());
    int64_t cost = 0;
    int64_t last_height = B.at(0);
    for (int64_t i = 1; i < N; i++) {
      if (bit & (1 << i)) {
        if (B.at(i) <= last_height) {
          int64_t diff = last_height - B.at(i) + 1;
          B.at(i) += diff;
          cost += diff;
        }
      }
      last_height = std::max(last_height, B.at(i));
    }

    int64_t count = 1;
    last_height = B.at(0);
    for (int64_t i = 1; i < N; i++) {
      if (B.at(i) > last_height) {
        count++;
      }
      last_height = std::max(last_height, B.at(i));
    }

    if (count >= K) {
      answer = std::min(answer, cost);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
