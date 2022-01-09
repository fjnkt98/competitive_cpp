#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t square_number = 0;
  for (int64_t i = 1; i * i <= N; i++) {
    square_number++;
  }

  std::cout << N - square_number << std::endl;

  return 0;
}