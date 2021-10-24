#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

int main() {
  int64_t M;
  std::cin >> M;
  std::vector<std::vector<int64_t>> graph(9);
  for (int64_t i = 0; i < M; i++) {
    int64_t u, v;
    std::cin >> u >> v;

    graph.at(u - 1).push_back(v - 1);
    graph.at(v - 1).push_back(u - 1);
  }

  std::string S = "888888888";
  for (int64_t i = 0; i < 8; i++) {
    int64_t p;
    std::cin >> p;
    S.at(p - 1) = static_cast<char>(i + '0');
  }

  std::queue<std::string> candidate;
  candidate.push(S);

  std::map<std::string, int64_t> shortest_path;
  shortest_path[S] = 0;

  while (!candidate.empty()) {
    std::string current_state = candidate.front();
    candidate.pop();

    int64_t empty_place;
    for (int64_t i = 0; i < 9; i++) {
      if (current_state.at(i) == '8') {
        empty_place = i;
      }
    }

    for (auto next_node : graph.at(empty_place)) {
      std::string next_state = current_state;
      std::swap(next_state.at(next_node), next_state.at(empty_place));

      if (shortest_path.count(next_state) == 0) {
        shortest_path[next_state] = shortest_path[current_state] + 1;
        candidate.push(next_state);
      }
    }
  }

  if (shortest_path.count("012345678") == 0) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << shortest_path["012345678"] << std::endl;
  }

  return 0;
}
