#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t X, Y;
  std::cin >> X >> Y;

  int64_t answer = 0;
  if (X == 0) {
    if (Y == 0) {
      answer = 0;
    } else if (Y > 0) {
      answer = std::abs(Y);
    } else {
      answer = std::abs(Y) + 1;
    }
  } else if (Y == 0) {
    if (X > 0) {
      answer = std::abs(X) + 1;
    } else {
      answer = std::abs(X);
    }
  } else if ((X < 0 && Y < 0) || (X > 0 && Y > 0)) {
    if (X < Y) {
      answer = std::abs(Y - X);
    } else {
      answer = std::abs(Y - X) + 2;
    }
  } else {
    answer = std::abs(std::abs(Y) - std::abs(X)) + 1;
  }

  std::cout << answer << std::endl;

  return 0;
}
