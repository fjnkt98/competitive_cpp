#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> dice(N, std::vector<int64_t>(6));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < 6; j++) {
      std::cin >> dice.at(i).at(j);
    }
  }

  std::vector<std::vector<int64_t>> prod(N, std::vector<int64_t>(6));
  for (int64_t j = 0; j < 6; j++) {
    prod.at(0).at(j) = dice.at(0).at(j);
  }
  for (int64_t i = 1; i < N; i++) {
    for (int64_t j = 0; j < 6; j++) {
      int64_t sum = 0;
      for (int64_t k = 0; k < 6; k++) {
        sum += prod.at(i - 1).at(k) * dice.at(i).at(j);
      }
      prod.at(i).at(j) = sum % 1000000007;
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < 6; i++) {
    answer += prod.at(N - 1).at(i);
    answer = answer % 1000000007;
  }
  std::cout << answer << std::endl;

  return 0;
}
