#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t answer = 0;
  for (int64_t i = 1; i * i <= N; i++) {
    answer++;
  }

  std::cout << answer << std::endl;

  return 0;
}