#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<class T> bool choose_minimum(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b, c;
    std::cin >> a >> b >> c;
    graph.at(a - 1).push_back(std::make_pair(b - 1, -c));
  }

  bool exist_negative_cycle = false;
  std::vector<int64_t> distance(N, 1LL << 60);
  distance.at(0) = 0;

  for (int64_t i = 0; i < N; i++) {
    bool update = false;
    for (int64_t j = 0; j < N; j++) {
      if (distance.at(j) == 1LL << 60) continue;

      for (auto e : graph.at(j)) {
        if (choose_minimum(distance.at(e.first), distance.at(j) + e.second)) {
          update = true;
        }
      }
    }

    if (!update) {
      break;
    }

    if (i == N - 1 && update) {
      exist_negative_cycle = true;
    }
  }

  if (exist_negative_cycle) {
    std::cout << "inf" << std::endl;
  } else {
    std::cout << -distance.at(N - 1) << std::endl;
  }
}
