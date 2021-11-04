#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<std::vector<int64_t>> A(3, std::vector<int64_t>(3));
  for (int64_t i = 0; i < 3; i++) {
    for (int64_t j = 0; j < 3; j++) {
      std::cin >> A.at(i).at(j);
    }
  }
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }

  std::vector<std::vector<int64_t>> token(3, std::vector<int64_t>(3, 0));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < 3; j++) {
      for (int64_t k = 0; k < 3; k++) {
        if (B.at(i) == A.at(j).at(k)) {
          token.at(j).at(k) = 1;
        }
      }
    }
  }

  bool bingo = false;
  for (int64_t i = 0; i < 3; i++) {
    bool ok = true;
    for (int64_t j = 0; j < 3; j++) {
      if (token.at(i).at(j) == 0) {
        ok = false;
      }
    }
    if (ok) bingo = true;
  }

  for (int64_t j = 0; j < 3; j++) {
    bool ok = true;
    for (int64_t i = 0; i < 3; i++) {
      if (token.at(i).at(j) == 0) {
        ok = false;
      }
    }
    if (ok) bingo = true;
  }

  if (token.at(0).at(0) == 1 && token.at(1).at(1) == 1 && token.at(2).at(2) == 1) {
    bingo = true;
  }
  if (token.at(0).at(2) == 1 && token.at(1).at(1) == 1 && token.at(2).at(0) == 1) {
    bingo = true;
  }

  if (bingo) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
