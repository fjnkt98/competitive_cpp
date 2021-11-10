#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t sum_of_arithmetic_progression(int64_t init_term, int64_t diff, int64_t length) {
  return (length * (2 * init_term + (length - 1) * diff)) / 2;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  int64_t sum = 0;
  for (int64_t i = 0; i < N; i++) {
    sum += sum_of_arithmetic_progression(A.at(i), 1, B.at(i) - A.at(i) + 1);
  }

  std::cout << sum << std::endl;

  return 0;
}
