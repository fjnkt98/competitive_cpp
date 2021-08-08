#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t& a : A) {
    std::cin >> a;
  }
  int64_t Q;
  std::cin >> Q;
  std::vector<int64_t> M(Q);
  for (int64_t& m : M) {
    std::cin >> m;
  }

  for (int64_t& m : M) {
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(N + 1, false));
    dp.at(0).assign(N + 1, true);

    for (int64_t i = 1; i <= m; i++) {
      for (int64_t j = 1; j <= N; j++) {
        // When choosing i-th element
        if (i - A.at(j - 1) >= 0) {
          if (dp.at(i - A.at(j - 1)).at(j - 1)) {
            dp.at(i).at(j) = true;
          }
        }
        // When don't choose i-th element
        if (dp.at(i).at(j - 1)) {
          dp.at(i).at(j) = true;
        }
      }
    }

    if (dp.at(m).at(N)) {
      std::cout << "yes" << std::endl;
    } else {
      std::cout << "no" << std::endl;
    }
  }

  return 0;
}
