#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  std::vector<int64_t> A(3);
  std::cin >> A.at(0) >> A.at(1) >> A.at(2);

  std::sort(A.begin(), A.end());

  bool ok = false;
  do {
    if (A.at(2) - A.at(1) == A.at(1) - A.at(0)) {
      ok = true;
    }
  } while (std::next_permutation(A.begin(), A.end()));

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
