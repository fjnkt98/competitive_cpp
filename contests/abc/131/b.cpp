#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N, L;
  std::cin >> N >> L;
  std::vector<int64_t> taste(N);
  for (int64_t i = 0; i < N; i++) {
    taste.at(i) = L + i;
  }

  std::vector<int64_t> taste_abs(N);
  for (int64_t i = 0; i < N; i++) {
    taste_abs.at(i) = std::abs(taste.at(i));
  }

  int64_t index = std::distance(taste_abs.begin(), std::min_element(taste_abs.begin(), taste_abs.end()));

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    if (i != index) {
      answer += taste.at(i);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
