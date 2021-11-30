#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::map<int64_t, int64_t> count;
  for (int64_t i = 0; i < N; i++) {
    count[A.at(i)]++;
  }

  int64_t answer = 0;
  for (auto c : count) {
    int64_t x = c.first;
    int64_t quantity = c.second;

    if (x == quantity) continue;

    if (x < quantity) {
      answer += (quantity - x);
    } else {
      answer += quantity;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
