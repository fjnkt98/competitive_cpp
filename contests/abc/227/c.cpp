#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t count = 0;
  for (int64_t i = 1; i * i * i <= N; i++) {
    for (int64_t j = i; i * j * j <= N; j++) {
      count += N / (i * j) - j + 1;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
