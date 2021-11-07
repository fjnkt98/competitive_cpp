#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::map<int64_t, int64_t> count;
  for (int64_t i = 0; i < N; i++) {
    int64_t a;
    std::cin >> a;
    A.at(i) = a;
    count[a]++;
  }

  int64_t answer = 0;
  for (int64_t X = 0; X <= 100000; X++) {
    int64_t local_count = count[X - 1] + count[X] + count[X + 1];
    answer = std::max(answer, local_count);
  }

  std::cout << answer << std::endl;

  return 0;
}
