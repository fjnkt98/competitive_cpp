#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, S, D;
  std::cin >> N >> S >> D;
  std::vector<int64_t> X(N);
  std::vector<int64_t> Y(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i) >> Y.at(i);
  }

  bool ok = false;
  for (int64_t i = 0; i < N; i++) {
    if (X.at(i) < S && Y.at(i) > D) {
      ok = true;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No"  << std::endl;
  }

  return 0;
}
