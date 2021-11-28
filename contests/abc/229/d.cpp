#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  int64_t K;
  std::cin >> S >> K;

  int64_t N = static_cast<int64_t>(S.size());

  std::vector<int64_t> cumsum(N + 1, 0);
  for (int64_t i = 0; i < N; i++) {
    if (S.at(i) == '.') {
      cumsum.at(i + 1) += cumsum.at(i) + 1;
    } else {
      cumsum.at(i + 1) += cumsum.at(i);
    }
  }

  int64_t answer = 0;
  int64_t right = 0;
  for (int64_t left = 0; left < N; left++) {
    while (right < N && cumsum.at(right + 1) - cumsum.at(left) <= K) {
      right++;
    }

    answer = std::max(answer, right - left);
  }

  std::cout << answer << std::endl;

  return 0;
}
