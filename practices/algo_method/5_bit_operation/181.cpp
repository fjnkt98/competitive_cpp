#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  std::cout << (A ^ B) << std::endl;

  return 0;
}