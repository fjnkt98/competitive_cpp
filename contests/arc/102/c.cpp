#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N, K;
  std::cin >> N >> K;

  int64_t answer = 0;
  int64_t count = 0;
  for (int64_t i = 1; i <= N; i++) {
    if (i % K == 0) {
      count++;
    }
  }
  answer = count * count * count;

  if (K % 2 == 0) {
    count = 0;
    for (int64_t i = 1; i <= N; i++) {
      if (i % K == K / 2) {
        count++;
      }
    }
    answer += count * count * count;
  }

  std::cout << answer << std::endl;

  return 0;
}