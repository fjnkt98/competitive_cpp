#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> d(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> d.at(i);
  }

  std::set<int64_t> mochi;
  for (int64_t i = 0; i < N; i++) {
    mochi.insert(d.at(i));
  }

  std::cout << mochi.size() << std::endl;

  return 0;
}
