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
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t answer = A.at(0);
  for (int64_t i = 1; i < N; i++) {
    answer = gcd(answer, A.at(i));
  }

  std::cout << answer << std::endl;

  return 0;
}
