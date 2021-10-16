/*
 * https://atcoder.jp/contests/abc145/tasks/abc145_c
 */
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
  std::vector<int64_t> x(N);
  std::vector<int64_t> y(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> x.at(i) >> y.at(i);
  }

  std::vector<int64_t> order(N);
  std::iota(order.begin(), order.end(), 0);

  std::vector<double> distances;
  int64_t count = 0;
  do {
    double sum = 0.0;
    for (int64_t i = 1; i < N; i++) {
      sum += std::sqrt(
          (x.at(order.at(i)) - x.at(order.at(i - 1))) * (x.at(order.at(i)) - x.at(order.at(i - 1)))
          + (y.at(order.at(i)) - y.at(order.at(i - 1))) * (y.at(order.at(i)) - y.at(order.at(i - 1)))
          );
    }
    distances.push_back(sum);
    count++;
  } while (std::next_permutation(order.begin(), order.end()));

  for (double& d : distances) {
    d /= count;
  }

  double sum = std::accumulate(distances.begin(), distances.end(), 0.0);

  std::cout << std::fixed << std::setprecision(10) << sum << std::endl;

  return 0;
}
