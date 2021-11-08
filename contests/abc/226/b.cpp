#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  int64_t N;
  std::cin >> N;
  std::set<std::vector<int64_t>> count;
  for (int64_t i = 0; i < N; i++) {
    int64_t L;
    std::cin >> L;
    std::vector<int64_t> A(L);
    for (int64_t j = 0; j < L; j++) {
      std::cin >> A.at(j);
    }
    count.insert(A);
  }

  std::cout << count.size() << std::endl;

  return 0;
}
