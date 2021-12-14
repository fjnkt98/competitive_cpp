#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t a, b, x;
  std::cin >> a >> b >> x;

  int64_t answer = b / x - a / x;
  if (a % x == 0) {
    answer++;
  }

  std::cout << answer << std::endl;

  return 0;
}
