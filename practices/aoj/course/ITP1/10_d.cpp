#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<double> x(N);
  std::vector<double> y(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> x.at(i);
  }
  for (int64_t i = 0; i < N; i++) {
    std::cin >> y.at(i);
  }

  double manhattan_distance = 0;
  for (int64_t i = 0; i < N; i++) {
    manhattan_distance += std::fabs(x.at(i) - y.at(i));
  }

  double euclidean_distance = 0;
  for (int64_t i = 0; i < N; i++) {
    euclidean_distance += std::pow(x.at(i) - y.at(i), 2);
  }
  euclidean_distance = std::sqrt(euclidean_distance);

  double minkowski_distance_3 = 0;
  for (int64_t i = 0; i < N; i++) {
    minkowski_distance_3 += std::pow(std::fabs(x.at(i) - y.at(i)), 3);
  }
  minkowski_distance_3 = std::cbrt(minkowski_distance_3);

  double chebyshev_distance = 0;
  for (int64_t i = 0; i < N; i++) {
    if (chebyshev_distance < std::fabs(x.at(i) - y.at(i))) {
      chebyshev_distance = std::fabs(x.at(i) - y.at(i));
    }
  }

  std::cout << std::fixed << std::setprecision(8) << manhattan_distance << std::endl;
  std::cout << std::fixed << std::setprecision(8) << euclidean_distance << std::endl;
  std::cout << std::fixed << std::setprecision(8) << minkowski_distance_3 << std::endl;
  std::cout << std::fixed << std::setprecision(8) << chebyshev_distance << std::endl;

  return 0;
}
