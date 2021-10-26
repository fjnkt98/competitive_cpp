#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t N;
  std::cin >> N;
  int64_t M = 1;
  for (int64_t i = 0; i < N; i++) {
    M *= 2;
  }
  std::vector<std::pair<int64_t, int64_t>> A(M);
  for (int64_t i = 0; i < M; i++) {
    int64_t a;
    std::cin >> a;

    A.at(i) = std::make_pair(a, i + 1);
  }

  std::vector<std::pair<int64_t, int64_t>> winners(M);
  std::copy(A.begin(), A.end(), winners.begin());
  for (int64_t i = N; i > 1; i--) {
    for (size_t j = 0; j < winners.size() / 2; j++) {
      if (winners.at(2 * j).first > winners.at(2 * j + 1).first) {
        winners.at(j) = winners.at(2 * j);
      } else {
        winners.at(j) = winners.at(2 * j + 1);
      }
    }

    winners.resize(winners.size() / 2);
  }

  if (winners.at(0).first > winners.at(1).first) {
    std::cout << winners.at(1).second << std::endl;
  } else {
    std::cout << winners.at(0).second << std::endl;
  }

  return 0;
}
