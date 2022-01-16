#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  std::vector<int64_t> x(Q);
  std::vector<int64_t> k(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> x.at(i) >> k.at(i);
  }

  std::map<int64_t, std::vector<int64_t>> dictionary;
  for (int64_t i = 0; i < N; i++) {
    dictionary[A.at(i)].push_back(i + 1);
  }

  for (int64_t i = 0; i < Q; i++) {
    if (dictionary[x.at(i)].size() == 0 ||
        dictionary[x.at(i)].size() < k.at(i)) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << dictionary[x.at(i)].at(k.at(i) - 1) << std::endl;
    }
  }

  return 0;
}
