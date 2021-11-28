#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string A, B;
  std::cin >> A >> B;

  std::reverse(A.begin(), A.end());
  std::reverse(B.begin(), B.end());

  bool is_hard = false;
  for (size_t i = 0; i < std::min(A.size(), B.size()); i++) {
    int64_t digitA = static_cast<int64_t>(A.at(i) - '0');
    int64_t digitB = static_cast<int64_t>(B.at(i) - '0');

    if (digitA + digitB >= 10) {
      is_hard = true;
    }
  }

  if (is_hard) {
    std::cout << "Hard" << std::endl;
  } else {
    std::cout << "Easy" << std::endl;
  }

  return 0;
}
