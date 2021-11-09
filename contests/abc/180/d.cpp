#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t X, Y, A, B;
  std::cin >> X >> Y >> A >> B;

  int64_t experience = 0;
  int64_t strength = X;
  while (static_cast<double>(strength) * A <= 2e18 && A * strength <= strength + B && A * strength < Y) {
    strength *= A;
    experience++;
  }

  std::cout << experience + (Y - strength - 1) / B << std::endl;

  return 0;
}
