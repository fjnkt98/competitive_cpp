#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::set<int64_t> count;
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
    count.insert(A.at(i));
  }

  std::cout << count.size() << std::endl;

  return 0;
}
