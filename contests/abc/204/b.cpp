#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> tree(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> tree.at(i);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    if (tree.at(i) > 10) {
      count += tree.at(i) - 10;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
