#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t H, W;
  std::cin >> H >> W;
  std::vector<std::vector<int64_t>> A(H, std::vector<int64_t>(W));
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      std::cin >> A.at(i).at(j);
    }
  }
  std::vector<std::vector<int64_t>> B(H, std::vector<int64_t>(W));
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      std::cin >> B.at(i).at(j);
    }
  }

  bool ok = true;
  int64_t operation_count = 0;
  for (int64_t i = 0; i < H - 1; i++) {
    for (int64_t j = 0; j < W - 1; j++) {
      if (A.at(i).at(j) != B.at(i).at(j)) {
        int64_t diff = B.at(i).at(j) - A.at(i).at(j);
        A.at(i).at(j) += diff;
        A.at(i).at(j + 1) += diff;
        A.at(i + 1).at(j) += diff;
        A.at(i + 1).at(j + 1) += diff;
        operation_count += std::abs(diff);
      }
    }
    if (A.at(i).at(W - 1) != B.at(i).at(W - 1)) {
      ok = false;
    }
  }
  for (int64_t j = 0; j < W; j++) {
    if (A.at(H - 1).at(j) != B.at(H - 1).at(j)) {
      ok = false;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
    std::cout << operation_count << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
