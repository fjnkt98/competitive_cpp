#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C, X;
  std::cin >> A >> B >> C >> X;

  int64_t count = 0;
  for (int64_t i = 0; i <= A; i++) {
    for (int64_t j = 0; j <= B; j++) {
      for (int64_t k = 0; k <= C; k++) {
        int64_t sum = i * 500 + j * 100 + k * 50;
        if (sum == X) {
          count++;
        }
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}
