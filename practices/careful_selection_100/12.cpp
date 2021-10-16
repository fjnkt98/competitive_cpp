/*
 * https://atcoder.jp/contests/abc002/tasks/abc002_4
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::map<int64_t, std::set<int64_t>> relation;
  for (int64_t i = 0; i < M; i++) {
    int64_t x, y;
    std::cin >> x >> y;

    relation[x - 1].insert(y - 1);
    relation[y - 1].insert(x - 1);
  }

  int64_t answer = 0;
  for (int64_t bit = 0; bit < (1 << N); bit++) {
    std::vector<int64_t> faction;
    for (int64_t i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        faction.push_back(i);
      }
    }

    bool ok = true;
    for (size_t i = 0; i < faction.size(); i++) {
      for (size_t j = i + 1; j < faction.size(); j++) {
        if (relation[faction.at(i)].find(faction.at(j)) == relation[faction.at(i)].end()) {
          ok = false;
        }
      }
    }

    if (ok) {
      answer = std::max(answer, static_cast<int64_t>(faction.size()));
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
