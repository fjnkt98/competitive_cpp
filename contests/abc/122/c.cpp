#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::string S;
  std::cin >> S;

  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t l, r;
    std::cin >> l >> r;
    query.at(i) = std::make_pair(l - 1, r - 1);
  }

  std::vector<int64_t> cumsum(N + 1, 0);
  for (int64_t i = 1; i < N; i++) {
    if (S.at(i) == 'C' && S.at(i - 1) == 'A') {
      cumsum.at(i) = cumsum.at(i - 1) + 1;
    } else {
      cumsum.at(i) = cumsum.at(i - 1);
    }
  }
  cumsum.at(N) = cumsum.at(N - 1);

  for (int64_t i = 0; i < Q; i++) {
    int64_t l = query.at(i).first;
    int64_t r = query.at(i).second;

    std::cout << cumsum.at(r) - cumsum.at(l) << std::endl;
  }

  return 0;
}
