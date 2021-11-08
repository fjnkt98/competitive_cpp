#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::string N;
  for (auto c : S) {
    if (c != '.') {
      N.push_back(c);
    } else {
      break;
    }
  }

  if (static_cast<int64_t>(S.at(S.size() - 3) - '0') < 5) {
    std::cout << N << std::endl;
  } else {
    std::cout << std::stol(N) + 1 << std::endl;
  }

  return 0;
}
