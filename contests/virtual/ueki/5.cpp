#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::set<int64_t> set;
  for (int64_t i = 0; i <= N; i++) {
    set.insert(i);
  }

  for (int64_t i = 0; i < M; i++) {
    set.erase(A.at(i));
  }

  std::cout << *set.begin() << std::endl;

  int64_t answer = *set.begin();
  for (int64_t i = 0; i <= N - M; i++) {
    std::cout << "i: " << i << " ";
    for (auto e : set) {
      std::cout << e << " ";
    }
    std::cout << std::endl;

    if (i != N - M) set.erase(A.at(i + M));
    set.insert(A.at(i));
    answer = std::min(answer, *set.begin());
  }

  std::cout << answer << std::endl;

  return 0;
}