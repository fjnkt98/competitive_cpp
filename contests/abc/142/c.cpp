#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  std::vector<std::pair<int64_t, int64_t>> record(N);
  for (int64_t i = 0; i < N; i++) {
    record.at(i) = std::make_pair(A.at(i), i + 1);
  }
  std::sort(record.begin(), record.end());

  std::vector<int64_t> order;
  for (int64_t i = 0; i < N; i++) {
    order.push_back(record.at(i).second);
  }

  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << order.at(i);
  }
  std::cout << std::endl;

  return 0;
}
