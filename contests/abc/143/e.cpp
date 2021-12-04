#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

int main() {
  int64_t N, M, L;
  std::cin >> N >> M >> L;
  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(N);
  std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(N, 1LL << 60));
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b, c;
    std::cin >> a >> b >> c;

    graph.at(a - 1).push_back(std::make_pair(b - 1, c));
    graph.at(b - 1).push_back(std::make_pair(a - 1, c));

    dp.at(a - 1).at(b - 1) = c;
    dp.at(b - 1).at(a - 1) = c;
  }

  for (int64_t i = 0; i < N; i++) {
    dp.at(i).at(i) = 0;
  }

  int64_t Q;
  std::cin >> Q;
  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t s, t;
    std::cin >> s >> t;

    query.at(i) = std::make_pair(s - 1, t - 1);
  }

  for (int64_t k = 0; k < N; k++) {
    for (int64_t i = 0; i < N; i++) {
      for (int64_t j = 0; j < N; j++) {
        if (dp.at(i).at(j) > dp.at(i).at(k) + dp.at(k).at(j)) {
          dp.at(i).at(j) = dp.at(i).at(k) + dp.at(k).at(j);
        }
      }
    }
  }

  std::vector<std::vector<int64_t>> cost(N, std::vector<int64_t>(N, 1LL << 60));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      if (i == j) {
        cost.at(i).at(j) = 0;
      } else if (dp.at(i).at(j) <= L) {
        cost.at(i).at(j) = 1;
      }
    }
  }

  for (int64_t k = 0; k < N; k++) {
    for (int64_t i = 0; i < N; i++) {
      for (int64_t j = 0; j < N; j++) {
        if (cost.at(i).at(j) > cost.at(i).at(k) + cost.at(k).at(j)) {
          cost.at(i).at(j) = cost.at(i).at(k) + cost.at(k).at(j);
        }
      }
    }
  }

  for (int64_t i = 0; i < Q; i++) {
    int64_t s = query.at(i).first;
    int64_t t = query.at(i).second;

    if (cost.at(s).at(t) == 1LL << 60) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << cost.at(s).at(t) - 1 << std::endl;
    }
  }


  return 0;
}
