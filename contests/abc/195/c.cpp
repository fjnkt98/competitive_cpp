#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t count = 0;
  for (int64_t i = 1000; i <= 1000000000000000; i *= 1000) {
    if (N >= i) count+= N - (i - 1);
  }

  std::cout << count << std::endl;

  return 0;
}
