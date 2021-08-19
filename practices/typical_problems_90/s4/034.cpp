#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t answer = 0;
  int64_t right = 0;
  std::map<int64_t, int64_t> map;
  for (int64_t left = 0; left < N; left++) {
    while (right < N) {
      if (map.find(A.at(right)) == map.end() && map.size() >= K) {
        break;
      }
      map[A.at(right)]++;
      right++;
    }
    answer = std::max(answer, right - left);

    map[A.at(left)]--;
    if (map[A.at(left)] <= 0) {
      map.erase(A.at(left));
    }
  }

  std::cout << answer << std::endl;
  return 0;
}
