#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  int64_t N, M, Q;
  std::cin >> N >> M >> Q;
  std::vector<std::pair<int64_t, int64_t>> baggage(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t w, v;
    std::cin >> w >> v;
    baggage.at(i) = std::make_pair(v, w);
  }
  std::sort(baggage.begin(), baggage.end(), std::greater<std::pair<int64_t, int64_t>>());
  std::vector<int64_t> X(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> X.at(i);
  }
  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t l, r;
    std::cin >> l >> r;
    query.at(i) = std::make_pair(l - 1, r - 1);
  }

  for (int64_t i = 0; i < Q; i++) {
    int64_t L = query.at(i).first;
    int64_t R = query.at(i).second;

    std::vector<int64_t> box;
    for (int64_t j = 0; j < M; j++) {
      if (j < L || R < j) box.push_back(X.at(j));
    }
    std::sort(box.begin(), box.end());

    int64_t result = 0;
    for (int64_t j = 0; j < N; j++) {
      for (auto iter = box.begin(); iter != box.end(); iter++) {
        if (baggage.at(j).second <= *iter) {
          result += baggage.at(j).first;
          box.erase(iter);
          break;
        }
      }
    }

    std::cout << result << std::endl;
  }

  return 0;
}
