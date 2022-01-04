#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N, A, B;
  std::cin >> N >> A >> B;

  if ((B - A) % 2 == 0) {
    std::cout << (B - A) / 2 << std::endl;
  } else {
    std::cout << std::min(A - 1, N - B) + 1 + (B - A - 1) / 2 << std::endl;
  }

  return 0;
}