#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t base_k(std::string s, int64_t k) {
  int64_t answer = 0;
  int64_t pow = 1;
  std::reverse(s.begin(), s.end());
  for (int64_t i = 0; i < s.size(); i++) {
    answer += static_cast<int64_t>(s.at(i) - '0') * pow;
    pow *= k;
  }

  return answer;
}

int main() {
  int64_t K;
  std::string A, B;
  std::cin >> K >> A >> B;

  std::cout << base_k(A, K) * base_k(B, K) << std::endl;

  return 0;
}
