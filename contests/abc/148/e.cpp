#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  if (N % 2 == 1) {
    std::cout << 0 << std::endl;
  } else {
    int64_t answer = N / 10;
    N /= 10;

    int64_t divider = 5;
    while (divider <= N) {
      answer += N / divider;
      divider *= 5;
    }

    std::cout << answer << std::endl;
  }

  return 0;
}
