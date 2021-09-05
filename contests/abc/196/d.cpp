#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t dfs(int64_t r, int64_t c, int64_t a,
            int64_t H, int64_t W, int64_t A, int64_t B,
            std::vector<std::vector<bool>>& has_placed)
{
  if (r == H) return (a == 0 ? 1 : 0);
  if (c == W) return dfs(r + 1, 0, a, H, W, A, B, has_placed);
  if (has_placed.at(r).at(c)) return dfs(r, c + 1, a, H, W, A, B, has_placed);

  int64_t count = 0;
  if (r + 1 < H && !has_placed.at(r + 1).at(c) && a > 0) {
    has_placed.at(r).at(c) = true;
    has_placed.at(r + 1).at(c) = true;

    count += dfs(r, c + 1, a - 1, H, W, A, B, has_placed);

    has_placed.at(r).at(c) = false;
    has_placed.at(r + 1).at(c) = false;
  }

  if (c + 1 < W && !has_placed.at(r).at(c + 1) && a > 0) {
    has_placed.at(r).at(c) = true;
    has_placed.at(r).at(c + 1) = true;

    count += dfs(r, c + 1, a - 1, H, W, A, B, has_placed);

    has_placed.at(r).at(c) = false;
    has_placed.at(r).at(c + 1) = false;
  }

  count += dfs(r, c + 1, a, H, W, A, B, has_placed);

  return count;
}

int main() {
  int64_t H, W, A, B;
  std::cin >> H >> W >> A >> B;
  std::vector<std::vector<bool>> has_placed(H, std::vector<bool>(W, false));

  std::cout << dfs(0, 0, A, H, W, A, B, has_placed) << std::endl;

  return 0;
}
