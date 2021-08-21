#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t answer = -1;
  while (N != 0) {
    N /= 2;
    answer++;
  }

  std::cout << answer << std::endl;

  return 0;
}
