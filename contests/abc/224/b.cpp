#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t H, W;
  std::cin >> H >> W;
  std::vector<std::vector<int64_t>> A(H, std::vector<int64_t>(W));
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  bool ok = true;
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = i + 1; j < H; j++) {
      for (int64_t k = 0; k < W; k++) {
        for (int64_t l = k + 1; l < W; l++) {
          if (A.at(i).at(k) + A.at(j).at(l) > A.at(j).at(k) + A.at(i).at(l)) {
            ok = false;
          }
        }
      }
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }


  return 0;
}
