#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<std::vector<int64_t>> C(4, std::vector<int64_t>(4, 0));
  for (int64_t i = 1; i <= 3; i++) {
    for (int64_t j = 1; j <= 3; j++) {
      std::cin >> C.at(i).at(j);
    }
  }

  bool ok = true;
  for (int64_t a1 = 0; a1 < C.at(1).at(1); a1++) {
    int64_t b1 = C.at(1).at(1) - a1;
    int64_t b2 = C.at(1).at(2) - a1;
    int64_t a2 = C.at(2).at(1) - b1;
    int64_t a3 = C.at(3).at(1) - b1;
    int64_t b3 = C.at(1).at(3) - a1;
    if (C.at(2).at(2) != a2 + b2) ok = false;
    if (C.at(2).at(3) != a2 + b3) ok = false;
    if (C.at(3).at(2) != a3 + b2) ok = false;
    if (C.at(3).at(3) != a3 + b3) ok = false;
  }

  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
