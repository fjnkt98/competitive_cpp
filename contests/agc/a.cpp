#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C;
  std::cin >> A >> B >> C;

  int64_t init_a = A;
  int64_t init_b = B;
  int64_t init_c = C;

  int64_t count = 0;
  while (true) {
    if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
      break;
    }

    int64_t a = A / 2;
    int64_t b = B / 2;
    int64_t c = C / 2;

    A = b + c;
    B = a + c;
    C = a + b;
    count++;

    if (init_a == A && init_b == B && init_c == C) {
      std::cout << -1 << std::endl;
      return 0;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
