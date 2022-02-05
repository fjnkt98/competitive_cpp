#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

void f(std::string S, std::vector<int64_t>& list, int64_t L, int64_t R) {
  int64_t X = std::stoll(S);
  if (X > R || S.size() > 10) {
    return;
  }

  if (X >= L) {
    list.push_back(X);
  }

  int64_t digit = static_cast<int64_t>(S.back() - '0');
  std::string T = S;

  for (int64_t i = 0; i < (10 - digit); i++) {
    T.push_back(static_cast<char>((digit + i) + '0'));
    f(T, list, L, R);
    T.pop_back();
  }
}

int main() {
  int64_t L, R;
  std::cin >> L >> R;

  std::vector<int64_t> list;
  for (int64_t i = 1; i < 10; i++) {
    std::string S = std::to_string(i);

    f(S, list, L, R);
  }

  int64_t answer = std::accumulate(list.begin(), list.end(), 0LL);
  // for (auto iter = list.begin(); iter != list.end(); iter++) {
  //   if (iter != list.begin()) std::cout << " ";
  //   std::cout << *iter;
  // }
  // std::cout << std::endl;

  std::cout << answer << std::endl;

  return 0;
}