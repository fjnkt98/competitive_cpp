#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, A, X, Y;
  std::cin >> N >> A >> X >> Y;

  if (N <= A) {
    std::cout << N * X << std::endl;
  } else {
    std::cout << A * X + (N - A) * Y << std::endl;
  }

  return 0;
}
