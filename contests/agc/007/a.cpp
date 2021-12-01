#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::string>& A, int64_t r, int64_t c, int64_t& H, int64_t& W) {
  A.at(r).at(c) = '.';

  if (r + 1 < H &&A.at(r + 1).at(c) == '#') {
    dfs(A, r + 1, c, H, W);
  } else if (c + 1 < W &&A.at(r).at(c + 1) == '#') {
    dfs(A, r, c + 1, H, W);
  }
}

int main() {
  int64_t H, W;
  std::cin >> H >> W;

  std::vector<std::string> A(H);
  for (int64_t i = 0; i < H; i++) {
    std::cin >> A.at(i);
  }

  dfs(A, 0, 0, H, W);

  std::vector<std::string> reference(H, std::string(W, '.'));

  if (reference == A) {
    std::cout << "Possible" << std::endl;
  } else {
    std::cout << "Impossible" << std::endl;
  }

  return 0;
}
