#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> L(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> L.at(i);
  }

  bool ok = true;
  for (int64_t i = 0; i < N; i++) {
    int64_t excluded_sum = 0;
    for (int64_t j = 0; j < N; j++) {
      if (i == j) continue;
      excluded_sum += L.at(j);
    }

    if (L.at(i) >= excluded_sum) {
      ok = false;
    }
  }

  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
