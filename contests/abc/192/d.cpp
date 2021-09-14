#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string X;
  int64_t M;
  std::cin >> X >> M;

  if (X.size() == 1) {
    if (std::stol(X) <= M) std::cout << 1 << std::endl;
    else std::cout << 0 << std::endl;
    return 0;
  }

  int64_t d = 0;
  for (auto& c : X) {
    d = std::max(d, static_cast<int64_t>(c - '0'));
  }

  int64_t left = d;
  int64_t right = M + 1;
  while (right - left > 1) {
    int64_t mid = (left + right) / 2;

    int64_t v = 0;
    for (auto& c : X) {
      if (v > (M + mid - 1) / mid) {
        v = M + 1;
      } else {
        v = v * mid + static_cast<int64_t>(c - '0');
      }
    }
    if (v > M) {
      right = mid;
    } else {
      left = mid;
    }
  }

  std::cout << left - d << std::endl;

  return 0;
}
