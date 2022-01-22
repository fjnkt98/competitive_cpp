#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

template <class T>
bool choose_minimum(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

int main() {
  int64_t V, E, r;
  std::cin >> V >> E >> r;
  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(V);
  for (int64_t i = 0; i < E; i++) {
    int64_t s, t, d;
    std::cin >> s >> t >> d;

    graph.at(s).push_back(std::make_pair(t, d));
  }

  std::vector<int64_t> distance(V, 1LL << 60);
  distance.at(r) = 0;

  std::priority_queue<std::pair<int64_t, int64_t>,
                      std::vector<std::pair<int64_t, int64_t>>,
                      std::greater<std::pair<int64_t, int64_t>>>
      heap;

  heap.push(std::make_pair(distance.at(r), r));

  while (!heap.empty()) {
    int64_t v = heap.top().second;
    int64_t d = heap.top().first;
    heap.pop();

    if (d > distance.at(v)) continue;

    for (auto edge : graph.at(v)) {
      if (choose_minimum(distance.at(edge.first),
                         distance.at(v) + edge.second)) {
        heap.push(std::make_pair(distance.at(edge.first), edge.first));
      }
    }
  }

  for (int64_t i = 0; i < V; i++) {
    if (distance.at(i) == 1LL << 60) {
      std::cout << "INF" << std::endl;
    } else {
      std::cout << distance.at(i) << std::endl;
    }
  }

  return 0;
}