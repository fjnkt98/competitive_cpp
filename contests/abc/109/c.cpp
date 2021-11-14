#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t gcd(int64_t x, int64_t y) {
 if (x < 0 || x < 0) return -1;

 if (y == 0) return x;
  else return gcd(y, x % y);
}

int main() {
  int64_t N, X;
  std::cin >> N >> X;
  std::vector<int64_t> x(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> x.at(i);
  }
  x.push_back(X);

  if (N == 1) {
    std::cout << std::abs(x.at(1) - x.at(0)) << std::endl;
    return 0;
  }

  std::sort(x.begin(), x.end());

  std::vector<int64_t> diff(N);
  for (int64_t i = 0; i < N; i++) {
    diff.at(i) = x.at(i + 1) - x.at(i);
  }

  int64_t answer = gcd(diff.at(0), diff.at(1));
  for (int64_t i = 1; i < N; i++) {
    answer = gcd(answer, diff.at(i));
  }

  std::cout << answer << std::endl;

  return 0;
}
