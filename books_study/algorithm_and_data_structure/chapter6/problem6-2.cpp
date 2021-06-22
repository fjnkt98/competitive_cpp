#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  
  std::vector<int64_t> a(N);
  std::vector<int64_t> b(N);
  std::vector<int64_t> c(N);

  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }
  for (int64_t i = 0; i < N; i++) {
    std::cin >> b.at(i);
  }
  for (int64_t i = 0; i < N; i++) {
    std::cin >> c.at(i);
  }

  std::sort(a.begin(), a.end());
  std::sort(c.begin(), c.end());

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    count +=
      (std::lower_bound(a.begin(), a.end(), b.at(i)) - a.begin())
      * (c.end() - std::upper_bound(c.begin(), c.end(), b.at(i)));
  }

  std::cout << count << std::endl;

  return 0;
}
