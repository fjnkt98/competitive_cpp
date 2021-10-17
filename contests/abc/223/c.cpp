#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  std::vector<double> time(N);
  for (int64_t i = 0; i < N; i++) {
    time.at(i) = static_cast<double>(A.at(i)) / B.at(i);
  }
  double sum = std::accumulate(time.begin(), time.end(), 0.0);

  double sim_time = sum / 2;
  double distance = 0.0;
  int64_t i = 0;
  for (i = 0; i < N; i++) {
    if (sim_time - time.at(i) > 0 ) {
      sim_time -= time.at(i);
    } else {
      break;
    }

    distance += time.at(i) * B.at(i);
  }

  distance += sim_time * B.at(i);
  std::cout << std::fixed << std::setprecision(10) << distance << std::endl;

  return 0;
}
