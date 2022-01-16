#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;

  int64_t a = static_cast<int64_t>(S.at(0) - '0');
  int64_t b = static_cast<int64_t>(S.at(1) - '0');
  int64_t c = static_cast<int64_t>(S.at(2) - '0');

  int64_t answer = 0;
  answer += a * 100 + b * 10 + c;
  answer += b * 100 + c * 10 + a;
  answer += c * 100 + a * 10 + b;

  std::cout << answer << std::endl;

  return 0;
}
