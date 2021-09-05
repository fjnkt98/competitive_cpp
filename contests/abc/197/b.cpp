#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t H, W, X, Y;
  std::cin >> H >> W >> X >> Y;
  X--;
  Y--;
  std::vector<std::string> maze(H);
  for (int64_t i = 0; i < H; i++) {
    std::cin >> maze.at(i);
  }

  int64_t count = 0;
  for (int64_t i = X; i >= 0; i--) {
    if (maze.at(i).at(Y) == '.') count++;
    else break;
  }
  for (int64_t i = X; i < H; i++) {
    if (maze.at(i).at(Y) == '.') count++;
    else break;
  }
  for (int64_t i = Y; i >= 0; i--) {
    if (maze.at(X).at(i) == '.') count++;
    else break;
  }
  for (int64_t i = Y; i < W; i++) {
    if (maze.at(X).at(i) == '.') count++;
    else break;
  }

  count -= 3;
  std::cout << count << std::endl;

  return 0;
}
