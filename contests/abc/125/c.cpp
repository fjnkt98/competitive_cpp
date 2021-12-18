#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t gcd(int64_t x, int64_t y) {
  if (y == 0) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N + 2);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> L(N + 2);
  L.at(0) = 0;
  L.at(1) = A.at(1);
  for (int64_t i = 2; i <= N; i++) {
    L.at(i) = gcd(L.at(i - 1), A.at(i));
  }

  std::vector<int64_t> R(N + 2);
  R.at(N + 1) = 0;
  R.at(N) = A.at(N);
  for (int64_t i = N - 1; i > 0; i--) {
    R.at(i) = gcd(R.at(i + 1), A.at(i));
  }

  int64_t answer = std::max(L.at(N - 1), R.at(2));
  for (int64_t i = 2; i < N; i++) {
    answer = std::max(answer, gcd(L.at(i - 1), R.at(i + 1)));
  }

  std::cout << answer << std::endl;

  return 0;
}
