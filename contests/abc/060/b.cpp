#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C;
  std::cin >> A >> B >> C;

  bool ok = false;
  for (int64_t i = 1; i < 100000; i++) {
    if (A * i - C <= 0) continue;
    if ((A * i - C) % B == 0) {
      ok = true;
    }
  }

  if (ok) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;

  return 0;
}
