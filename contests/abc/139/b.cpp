#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  if (B == 1) {
    std::cout << 0 << std::endl;
    return 0;
  }

  int64_t count = 0;
  int64_t total_outlet = 1;
  while (total_outlet < B) {
    total_outlet += (A - 1);
    count++;
  }

  std::cout << count << std::endl;

  return 0;
}
