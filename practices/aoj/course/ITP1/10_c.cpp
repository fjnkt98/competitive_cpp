#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

int main() {
  while (true) {
    int64_t N;
    std::cin >> N;

    if (N == 0) {
      break;
    }

    std::vector<int64_t> points(N);
    for (int64_t i = 0; i < N; i++) {
      std::cin >> points.at(i);
    }

    int64_t sum = 0;
    for (int64_t i = 0; i < N; i++) {
      sum += points.at(i);
    }

    double mean = static_cast<double>(sum) / N;

    double stddev = 0;
    for (int64_t i = 0; i < N; i++) {
      stddev += std::pow(static_cast<double>(points.at(i)) - mean, 2);
    }
    stddev /= N;

    std::cout << std::fixed << std::setprecision(8)<< std::sqrt(stddev) << std::endl;

  }

  return 0;
}
