#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> s(M);
  std::vector<int64_t> c(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> s.at(i) >> c.at(i);
  }

  if (N == 1) {
    int64_t answer = 1LL << 60;
    for (int64_t i = 0; i <= 9; i++) {
      std::string S = std::to_string(i);

      bool ok = true;
      for (int64_t j = 0; j < M; j++) {
        if (static_cast<int64_t>(S.at(s.at(j) - 1) - '0') != c.at(j)) {
          ok = false;
        }
      }
      if (ok) {
        answer = std::min(answer, i);
      }
    }
    if (answer == 1LL << 60) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << answer << std::endl;
    }
  } else if (N == 2) {
    int64_t answer = 1LL << 60;
    for (int64_t i = 10; i <= 99; i++) {
      std::string S = std::to_string(i);

      bool ok = true;
      for (int64_t j = 0; j < M; j++) {
        if (static_cast<int64_t>(S.at(s.at(j) - 1) - '0') != c.at(j)) {
          ok = false;
        }
      }
      if (ok) {
        answer = std::min(answer, i);
      }
    }
    if (answer == 1LL << 60) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << answer << std::endl;
    }
  } else {
    int64_t answer = 1LL << 60;
    for (int64_t i = 100; i <= 999; i++) {
      std::string S = std::to_string(i);

      bool ok = true;
      for (int64_t j = 0; j < M; j++) {
        if (static_cast<int64_t>(S.at(s.at(j) - 1) - '0') != c.at(j)) {
          ok = false;
        }
      }
      if (ok) {
        answer = std::min(answer, i);
      }
    }
    if (answer == 1LL << 60) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << answer << std::endl;
    }
  }

  return 0;
}
