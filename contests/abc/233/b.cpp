#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t L, R;
  std::string S;
  std::cin >> L >> R >> S;

  L--;
  R--;

  std::string A = S.substr(0, L);
  std::string B = S.substr(L, R - L + 1);
  std::string C = S.substr(R + 1);

  std::reverse(B.begin(), B.end());

  std::cout << A << B << C << std::endl;

  return 0;
}
