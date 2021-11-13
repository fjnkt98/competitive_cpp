#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t N, K;
  std::cin >> N >> K;

  double answer = 0.0;
  for (int64_t i = 1; i <= N; i++) {
    double L = static_cast<double>(K);
    int64_t count = 0;
    while (i < L) {
      L /= 2;
      count++;
    }

    double probability = 100.0;
    for (int64_t j = 0; j < count; j++) {
      probability *= 0.5;
    }

    answer += probability / N / 100;
  }

  std::cout << std::fixed << std::setprecision(12) << answer << std::endl;

  return 0;
}
