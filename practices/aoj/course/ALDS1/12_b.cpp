#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>

template<class T> bool choose_minimum(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t u, k;
    std::cin >> u >> k;
    for (int64_t j = 0; j < k; j++) {
      int64_t v, w;
      std::cin >> v >> w;
      graph.at(i).push_back(std::make_pair(v, w));
    }
  }

  std::vector<int64_t> distance(N, 1LL << 60);
  distance.at(0) = 0;

  std::priority_queue<std::pair<int64_t, int64_t>,
                      std::vector<std::pair<int64_t, int64_t>>,
                      std::greater<std::pair<int64_t, int64_t>>> heap;

  heap.push(std::make_pair(distance.at(0), 0));

  while (!heap.empty()) {
    int64_t v = heap.top().second;
    int64_t d = heap.top().first;
    heap.pop();

    if (d > distance.at(v)) {
      continue;
    }

    for (auto e : graph.at(v)) {
      if (choose_minimum(distance.at(e.first), distance.at(v) + e.second)) {
        heap.push(std::make_pair(distance.at(e.first), e.first));
      }
    }
  }

  for (int64_t i = 0; i < N; i++) {
    std::cout << i << " " << distance.at(i) << std::endl;
  }

  return 0;
}
