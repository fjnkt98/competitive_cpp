#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  std::vector<int64_t> P(26);
  for (auto& p : P) {
    std::cin >> p;
  }

  std::vector<char> S(26);
  for (int64_t i = 0; i < 26; i++) {
    S.at(i) = 'a' + (P.at(i) - 1);
  }

  for (auto c : S) {
    std::cout << c;
  }
  std::cout << std::endl;


  return 0;
}
