#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, A, B;
  std::cin >> N >> A >> B;

  // if (N == 1) {
  //   std::cout << 0 << std::endl;
  //   return 0;
  // } else if (N == 2) {
  //   std::cout << 1 << std::endl;
  //   return 0;
  // }

  // if (A > B) {
  //   std::cout << 0 << std::endl;
  //   return 0;
  // }

  int64_t minimum_sum = A * N + (B - A);
  int64_t maximum_sum = B * N - (B - A);
  int64_t answer = maximum_sum - minimum_sum + 1;

  std::cout << std::max(answer, 0L) << std::endl;

  return 0;
}