/*
 * AtCoder Grand Contest 009 A - Multiple Array
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  int64_t sum = 0;
  for (int64_t i = N - 1; i >= 0 ; i--) {
    A.at(i) += sum;
    int64_t reminder = A.at(i) % B.at(i);

    if (reminder != 0) {
      sum += (B.at(i) - reminder);
    }
  }

  std::cout << sum << std::endl;
}


