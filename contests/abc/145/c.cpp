#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<double> X(N);
  std::vector<double> Y(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i) >> Y.at(i);
  }

  std::vector<int64_t> route(N);
  std::iota(route.begin(), route.end(), 0);

  int64_t M = 1;
  for (int64_t i = 1; i <= N; i++) {
    M *= i;
  }

  double answer = 0.0;

  do {
    double distance = 0.0;

    for (int64_t i = 1; i < N; i++) {
      distance +=
          std::sqrt(std::pow((X.at(route.at(i)) - X.at(route.at(i - 1))), 2) +
                    std::pow(Y.at(route.at(i)) - Y.at(route.at(i - 1)), 2));
    }

    answer += distance / M;
  } while (std::next_permutation(route.begin(), route.end()));

  std::cout << std::fixed << std::setprecision(10) << answer << std::endl;

  return 0;
}