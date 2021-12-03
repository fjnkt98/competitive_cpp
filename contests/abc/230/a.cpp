#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::string numbering = "";
  if (N < 10) {
    numbering = "00" + std::to_string(N);
  } else if (N < 42) {
    numbering = "0" + std::to_string(N);
  } else {
    numbering = "0" + std::to_string(N + 1);
  }

  std::cout << "AGC" + numbering << std::endl;

  return 0;
}
