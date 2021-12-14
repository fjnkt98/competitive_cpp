#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, x;
  std::cin >> N >> x;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> B(N);
  std::copy(A.begin(), A.end(), B.begin());

  for (int64_t i = 0; i < N - 1; i++) {
    B.at(i) = std::min(B.at(i), x);

    if (B.at(i) + B.at(i + 1) > x) {
      B.at(i + 1) = x - B.at(i);
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    answer += A.at(i) - B.at(i);
  }

  std::cout << answer << std::endl;

  return 0;
}
