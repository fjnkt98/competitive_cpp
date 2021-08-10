#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, P, Q;
  std::cin >> N >> P >> Q;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < i; j++) {
      for (int64_t k = 0; k < j; k++) {
        for (int64_t l = 0; l < k; l++) {
          for (int64_t m = 0; m < l; m++) {
            if (A.at(i) * A.at(j) % P * A.at(k) % P * A.at(l) % P * A.at(m) % P == Q) {
              count++;
            }
          }
        }
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}
