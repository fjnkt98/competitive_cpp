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

  std::sort(A.begin(), A.end());

  int64_t answer = 0;
  int64_t sum = 0;
  for (int64_t i = 0; i < N - 1; i++) {
    sum += A.at(i);

    if (2 * sum < A.at(i + 1)) {
      answer = 0;
    } else {
      answer++;
    }
  }

  std::cout << answer + 1 << std::endl;

  return 0;
}
