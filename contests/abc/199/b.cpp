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
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }

  int64_t answer = 0;
  int64_t maximum_a = *std::max_element(A.begin(), A.end());
  int64_t minimum_b = *std::min_element(B.begin(), B.end());

  answer = minimum_b + 1 - maximum_a;
  if (answer < 0) {
    answer = 0;
  }

  std::cout << answer << std::endl;

  return 0;
}
