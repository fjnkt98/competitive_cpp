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

  int64_t minus_count = 0;
  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) < 0) minus_count++;
  }

  int64_t abs_sum = 0;
  for (int64_t i = 0; i < N; i++) {
    abs_sum += std::abs(A.at(i));
  }

  if (minus_count % 2 == 0) {
    std::cout << abs_sum << std::endl;
  } else {
    int64_t minimum_abs = 1LL << 60;
    for (int64_t i = 0; i < N; i++) {
      minimum_abs = std::min(minimum_abs, std::abs(A.at(i)));
    }

    std::cout << abs_sum - 2 * minimum_abs << std::endl;
  }

  return 0;
}
