#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string find_kth(int64_t i, int64_t j, int64_t k,
                    std::vector<std::vector<int64_t>>& dp)
{
  if (i == 0) {
    return std::string(j, 'b');
  } else if (j == 0) {
    return std::string(i, 'a');
  } else if (dp.at(i - 1).at(j) >= k) {
    return std::string("a") + find_kth(i - 1, j, k, dp);
  } else {
    return std::string("b") + find_kth(i, j - 1, k - dp.at(i - 1).at(j), dp);
  }
}

int main() {
  int64_t A, B, K;
  std::cin >> A >> B >> K;

  std::vector<std::vector<int64_t>> dp(A + 1, std::vector<int64_t>(B + 1, 0));
  dp.at(0).at(0) = 1;
  for (int64_t i = 0; i <= A; i++) {
    for (int64_t j = 0; j <= B; j++) {
      if (i > 0) {
        dp.at(i).at(j) += dp.at(i - 1).at(j);
      }
      if (j > 0) {
        dp.at(i).at(j) += dp.at(i).at(j - 1);
      }
    }
  }

  std::cout << find_kth(A, B, K, dp) << std::endl;

  return 0;
}
