#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, X;
  std::cin >> N >> X;
  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  int64_t total_price = 0;
  for (int64_t i = 0; i < N; i++) {
    if ((i + 1) % 2 == 0) {
      total_price += a.at(i) - 1;
    } else {
      total_price += a.at(i);
    }
  }

  if (total_price <= X) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
