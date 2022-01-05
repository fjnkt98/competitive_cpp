#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t X, Y;
  std::cin >> X >> Y;
  std::vector<int64_t> A;
  A.push_back(X);
  int64_t index = 1;
  while (true) {
    if (A.at(index - 1) <= Y / 2) {
      A.push_back(A.at(index - 1) * 2);
    } else {
      break;
    }
    index++;
  }

  std::cout << A.size() << std::endl;

  return 0;
}