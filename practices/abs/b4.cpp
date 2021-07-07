#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  std::sort(a.begin(), a.end(), std::greater<int64_t>{});

  int64_t alice = 0;
  int64_t bob = 0;
  for (int64_t i = 0; i < N; i++) {
    if (i % 2 == 0) {
      alice += a.at(i);
    } else {
      bob += a.at(i);
    }
  }

  std::cout << alice - bob << std::endl;

  return 0;
}
