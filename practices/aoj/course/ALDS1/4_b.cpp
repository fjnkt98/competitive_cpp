#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> S(N);
  for (int64_t& s : S) {
    std::cin >> s;
  }

  int64_t Q;
  std::cin >> Q;
  std::vector<int64_t> T(Q);
  for (int64_t& t : T) {
    std::cin >> t;
  }

  int64_t count = 0;
  for (int64_t& t : T) {
    if (std::binary_search(S.begin(), S.end(), t)) {
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
