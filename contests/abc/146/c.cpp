#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, X;
  std::cin >> A >> B >> X;

  int64_t left = 0;
  int64_t right = 1e9 + 1;


  while (right - left > 1) {
    int64_t mid = (right + left) / 2;

    int64_t price = A * mid + B * std::to_string(mid).size();

    if (price <= X) {
      left = mid;
    } else {
      right = mid;
    }
  }

  std::cout << left << std::endl;

  return 0;
}
