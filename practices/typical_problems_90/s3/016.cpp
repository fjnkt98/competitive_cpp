#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  int64_t A, B, C;
  std::cin >> A >> B >> C;

  int64_t minimum_amount_of_coins = 1LL << 60;
  for (int64_t i = 0; i < 9999; i++) {
    for (int64_t j = 0; j < 9999 - i; j++) {
      int64_t remain = N - A * i - B * j;
      int64_t k = remain / C;
      if (remain >= 0 &&remain % C == 0 && (i + j + k) <= 9999) {
        minimum_amount_of_coins = std::min(i + j + k, minimum_amount_of_coins);
      }
    }
  }

  std::cout << minimum_amount_of_coins << std::endl;

  return 0;
}
