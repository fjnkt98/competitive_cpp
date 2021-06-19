#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  std::sort(a.begin(), a.end());

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    count += static_cast<int64_t>(
        a.end() - std::upper_bound(a.begin(), a.end(), a.at(i))
        );
  }
  
  std::cout << count << std::endl;

  return 0;
}
