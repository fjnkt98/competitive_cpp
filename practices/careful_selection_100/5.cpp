/*
 * https://atcoder.jp/contests/abc095/tasks/arc096_a
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C, X, Y;
  std::cin >> A >> B >> C >> X >> Y;

  int64_t minimum_price = A * X + B * Y;
  for (int64_t i = 2; i <=  2 * std::max(X, Y); i += 2) {
    int64_t price = C * i;
    if (X - i / 2 > 0) price += A * (X - i / 2);
    if (Y - i / 2 > 0) price += B * (Y - i / 2);

    minimum_price = std::min(minimum_price, price);
  }

  std::cout << minimum_price << std::endl;

  return 0;
}
