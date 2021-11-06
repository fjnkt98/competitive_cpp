#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, X;
  std::cin >> A >> B >> X;

  if (A + B >= X && X >= A) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;

  return 0;
}
