#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  auto maximum = std::max_element(A.begin(), A.end());

  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) > *maximum / 2) {
      B.at(i) = *maximum - A.at(i);
    } else {
      B.at(i) = A.at(i);
    }
  }

  std::vector<int64_t> deviation(N);
  for (int64_t i = 0; i < N; i++) {
    deviation.at(i) = std::abs(B.at(i) - *maximum / 2);
  }

  std::vector<std::pair<int64_t, int64_t>> sorted_deviation(N);
  for (int64_t i = 0; i < N; i++) {
    sorted_deviation.at(i) = std::make_pair(deviation.at(i), i);
  }
  std::sort(sorted_deviation.begin(), sorted_deviation.end());

  if (std::distance(A.begin(), maximum) != sorted_deviation.at(0).second) {
    std::cout << *maximum << " " << A.at(sorted_deviation.at(0).second) << std::endl;
  } else {
    std::cout << *maximum << " " << A.at(sorted_deviation.at(1).second) << std::endl;
  }

  return 0;
}
