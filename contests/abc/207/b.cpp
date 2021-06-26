#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C, D;
  std::cin >> A >> B >> C >> D;

  if ((C * D - B) <= 0) {
    std::cout << -1 << std::endl;
    return 0;
  }

  int64_t count = 0;
  int64_t lightblue = A;
  int64_t red = 0;
  while (lightblue > red * D) {
    lightblue += B;
    red += C;

    count++;
  }

  std::cout << count << std::endl;

  return 0;
}
