#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t sx, sy, tx, ty;
  std::cin >> sx >> sy >> tx >> ty;

  int64_t dx = tx - sx;
  int64_t dy = ty - sy;

  std::cout << std::string(dy, 'U') << std::string(dx, 'R');
  std::cout << std::string(dy, 'D') << std::string(dx, 'L');
  std::cout << 'L' << std::string(dy + 1, 'U') << std::string(dx + 1, 'R') << 'D';
  std::cout << 'R' << std::string(dy + 1, 'D') << std::string(dx + 1, 'L') << 'U';
  std::cout << std::endl;

  return 0;
}
