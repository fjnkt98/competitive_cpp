#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string N;
  std::cin >> N;

  while (N.size() < 4) {
    N = "0" + N;
  }

  std::cout << N << std::endl;

  return 0;
}
