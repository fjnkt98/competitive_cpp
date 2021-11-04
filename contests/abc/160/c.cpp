#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t K, N;
  std::cin >> K >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> distance(N);
  for (int64_t i = 0; i < N - 1; i++) {
    distance.at(i) = A.at(i + 1) - A.at(i);
  }
  distance.at(N - 1) = K - A.at(N - 1) + A.at(0);

  std::cout << K - *std::max_element(distance.begin(), distance.end()) << std::endl;

  return 0;
}
