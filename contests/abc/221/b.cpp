#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S, T;
  std::cin >> S >> T;

  int64_t N = static_cast<int64_t>(S.size());

  if (S == T) {
    std::cout << "Yes" << std::endl;
    return 0;
  }

  bool ok = false;
  for (int64_t i = 0; i < N - 1; i++) {
    std::string Q = S;
    std::swap(Q.at(i), Q.at(i + 1));

    if (Q == T) {
      ok = true;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
