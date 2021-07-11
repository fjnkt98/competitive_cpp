#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<int64_t> ns;
  std::vector<int64_t> xs;
  int64_t N = 0;
  while (true) {
    int64_t n, x;
    std::cin >> n >> x;

    if (n == 0 && x == 0) {
      break;
    } else {
      ns.push_back(n);
      xs.push_back(x);
      N++;
    }
  }

  std::vector<int64_t> counts(N, 0);
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 1; j <= ns.at(i); j++) {
      for (int64_t k = j + 1; k <= ns.at(i); k++) {
        for (int64_t l = k + 1; l <= ns.at(i); l++) {
          if (j + k + l == xs.at(i)) {
            counts.at(i)++;
          }
        }
      }
    }
  }

  for (int64_t i = 0; i < N; i++) {
    std::cout << counts.at(i) << std::endl;
  }

  return 0;
}
