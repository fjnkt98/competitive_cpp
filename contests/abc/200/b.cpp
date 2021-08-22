#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;

  for (int64_t i = 0; i < K; i++) {
    if (N % 200 == 0) {
      N /= 200;
    } else {
      N *= 1000;
      N +=200;
    }
  }

  std::cout << N << std::endl;

  return 0;
}
