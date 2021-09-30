/*
 * https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

int main() {
  int64_t M;
  std::cin >> M;
  std::vector<int64_t> x(M);
  std::vector<int64_t> y(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> x.at(i) >> y.at(i);
  }

  int64_t N;
  std::cin >> N;
  std::vector<int64_t> X(N);
  std::vector<int64_t> Y(N);
  std::map<int64_t, std::set<int64_t>> p;
  for (int64_t i = 0; i < N; i++) {
    int64_t x, y;
    std::cin >> x >> y;
    X.at(i) = x;
    Y.at(i) = y;
    p[x].insert(y);
  }

  for (int64_t i = 0; i < N; i++) {
    int64_t diff_x = X.at(i) - x.at(0);
    int64_t diff_y = Y.at(i) - y.at(0);

    bool ok = true;
    for (int64_t j = 0; j < M; j++) {
      if (p[x.at(j) + diff_x].find(y.at(j) + diff_y) == p[x.at(j) + diff_x].end()) {
        ok = false;
      }
    }

    if (ok) {
      std::cout << diff_x << " " << diff_y << std::endl;
      break;
    }
  }

  return 0;
}
