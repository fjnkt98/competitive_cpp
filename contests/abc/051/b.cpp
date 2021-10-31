#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t K, S;
  std::cin >> K >> S;

  int64_t count = 0;
  for (int64_t i = 0; i <= K; i++) {
    for (int64_t j = 0; j <= K; j++) {
      if (S - i - j >= 0 && S - i - j <= K) count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
