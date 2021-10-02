#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t iterative_power(int64_t a, int64_t n) {
 if (n == 0) return 1;
 if (n == 1) return a;
 if (n % 2 == 1) return (a * iterative_power(a, n - 1));

 int64_t t = iterative_power(a, n / 2);
 return (t * t);
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::string> S(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> S.at(i);
  }

  std::vector<int64_t> dp(N + 1, 0);
  dp.at(0) = 1;
  for (int64_t i = 1; i <= N; i++) {
    if (S.at(i) == "AND") {
      dp.at(i) = dp.at(i - 1);
    } else {
      dp.at(i) = dp.at(i - 1) + iterative_power(2, i);
    }
  }

  std::cout << dp.at(N) << std::endl;

  return 0;
}
