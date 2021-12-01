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
  int64_t N, M;
  std::cin >> N >> M;
  std::string S, T;
  std::cin >> S >> T;

  int64_t lcm = N * M / gcd(N, M);

  bool ok = true;

  int64_t n = N / gcd(N, M);
  int64_t m = M / gcd(N, M);

  for (int64_t i = 0; i < gcd(N, M); i++) {
    if (S.at(i * n) != T.at(i * m)) {
      ok = false;
    }
  }

  if (ok) {
    std::cout << lcm << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }

  return 0;
}
