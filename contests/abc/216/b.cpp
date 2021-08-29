#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::string> S(N);
  std::vector<std::string> T(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i) >> T.at(i);
  }

  bool satisfy = false;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      if (S.at(i) == S.at(j) && T.at(i) == T.at(j)) {
        satisfy = true;
      }
    }
  }

  if (satisfy) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }


  return 0;
}
