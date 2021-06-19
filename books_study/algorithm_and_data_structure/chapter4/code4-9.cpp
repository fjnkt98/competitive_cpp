/*
 * Subset problem
 *
 * Solving by full search using recursive function
 *
 */

#include <iostream>
#include <vector>

bool func(int64_t i, int64_t w, const std::vector<int64_t>& a) {
  // Base case
  if (i == 0) {
    if (w == 0) {
      return true;
    } else {
      return false;
    }
  }

  // Case when don't choose a.at(i - 1)
  if (func(i - 1, w, a)) {
    return true;
  }

  // Case when choose a.at(i - 1)
  if (func(i - 1, w - a.at(i - 1), a)) {
    return true;
  }

  // Return false is both are false
  return false;
}

int main() {
  int64_t N;
  int64_t W;

  std::cin >> N >> W;

  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  if (func(N, W, a)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
