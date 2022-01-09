#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> x(N);
  std::vector<int64_t> y(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> x.at(i) >> y.at(i);
  }

  double answer = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      double distance = std::sqrt(std::pow(x.at(i) - x.at(j), 2) +
                                  std::pow(y.at(i) - y.at(j), 2));

      answer = std::max(answer, distance);
    }
  }

  std::cout << std::fixed << std::setprecision(10) << answer << std::endl;

  return 0;
}
