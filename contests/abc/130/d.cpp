#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> B(N);
  std::partial_sum(A.begin(), A.end(), B.begin());

  int64_t answer = 0;

  int64_t right = 0;
  for (int64_t left = 0; left < N; left++) {
    while (right < N) {
      int64_t sum = 0;
      if (left > 0) {
        sum = B.at(right) - B.at(left - 1);
      } else {
        sum = B.at(right);
      }
      if (sum >= K) break;
      right++;
    }

    answer += N - right;

    if (right == left){
      right++;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
