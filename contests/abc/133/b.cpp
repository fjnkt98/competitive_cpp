#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t N, D;
  std::cin >> N >> D;
  std::vector<std::vector<int64_t>> X(N, std::vector<int64_t>(D));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < D; j++) {
      std::cin >> X.at(i).at(j);
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      double distance = 0;
      for (int64_t k = 0; k < D; k++) {
        distance += (X.at(i).at(k) - X.at(j).at(k)) * (X.at(i).at(k) - X.at(j).at(k));
      }
      distance = std::sqrt(distance);

      if (std::abs(distance - static_cast<int64_t>(distance)) < 1e-10) {
        answer++;
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
