#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

void f(std::string S, std::vector<int64_t>& L) {
  if (std::stoll(S) > 1e10) {
    return;
  }

  L.push_back(std::stoll(S));

  int64_t digit = static_cast<int64_t>(S.back() - '0');

  std::string T = S;
  if (digit != 0) {
    T.push_back(static_cast<char>((digit - 1) + '0'));
    f(T, L);
    T.pop_back();
  }

  T.push_back(static_cast<char>(digit + '0'));
  f(T, L);
  T.pop_back();

  if (digit != 9) {
    T.push_back(static_cast<char>((digit + 1) + '0'));
    f(T, L);
    T.pop_back();
  }
}

int main() {
  int64_t K;
  std::cin >> K;

  std::vector<int64_t> L = {0};
  for (int64_t i = 1; i < 10; i++) {
    std::string S = std::to_string(i);
    f(S, L);
  }

  std::sort(L.begin(), L.end());
  std::cout << L.at(K) << std::endl;

  return 0;
}
