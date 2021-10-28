#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S, T;
  std::cin >> S >> T;

  std::sort(S.begin(), S.end());
  std::sort(T.begin(), T.end(), std::greater<char>{});

  if (S < T) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
