#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t N;
  std::cin >> N;

  std::string X = std::to_string(N);
  std::sort(X.begin(), X.end());

  int64_t answer = 0;
  do {
    for (int64_t i = 1; i < static_cast<int64_t>(X.size()); i++) {
      std::string A = X.substr(0, i);
      std::string B = X.substr(i);

      if (A.at(0) == '0' || B.at(0) == '0') {
        continue;
      }
      int64_t multiple = std::stoll(A) * std::stoll(B);
      answer = std::max(answer, multiple);
    }
  } while (std::next_permutation(X.begin(), X.end()));

  std::cout << answer << std::endl;

  return 0;
}
