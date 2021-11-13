#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::map<int64_t, int64_t> count;
  for (int64_t i = 0; i < N; i++) {
    count[A.at(i)]++;
  }

  std::vector<std::pair<int64_t, int64_t>> variety;
  for (auto c : count) {
    int64_t quantity = c.second;
    int64_t ball_number = c.first;

    variety.push_back(std::make_pair(quantity, ball_number));
  }
  std::sort(variety.begin(), variety.end());

  if (count.size() <= K) {
    std::cout << 0 << std::endl;
    return 0;
  } else {
    int64_t answer = 0;
    for (auto v : variety) {
      answer += v.first;
      count.erase(v.second);

      if (count.size() <= K) {
        break;
      }
    }
    std::cout << answer << std::endl;
  }


  return 0;
}
