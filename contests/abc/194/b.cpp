#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<int64_t, int64_t>> A(N);
  std::vector<std::pair<int64_t, int64_t>> B(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b;
    std::cin >> a >> b;

    A.at(i) = std::make_pair(a, i);
    B.at(i) = std::make_pair(b, i);
  }

  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());

  if (A.at(0).second != B.at(0).second) {
    std::cout << std::max(A.at(0).first, B.at(0).first) << std::endl;
  } else {
    int64_t minimum_time = 1LL << 60;
    minimum_time = std::min(minimum_time, A.at(0).first + B.at(0).first);
    minimum_time = std::min(minimum_time, std::max(A.at(0).first, B.at(1).first));
    minimum_time = std::min(minimum_time, std::max(A.at(1).first, B.at(0).first));

    std::cout << minimum_time << std::endl;
  }

  return 0;
}
