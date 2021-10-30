#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i);
  }

  std::sort(S.begin(), S.end());

  int64_t sum = std::accumulate(S.begin(), S.end(), static_cast<int64_t>(0));
  if (sum % 10 != 0) {
    std::cout << sum << std::endl;
  } else {
    int64_t answer = 0;
    for (int64_t i = 0; i < N; i++) {
      if ((sum - S.at(i)) % 10 != 0) {
        answer = sum - S.at(i);
        break;
      }
    }
    std::cout << answer << std::endl;
  }

  return 0;
}
