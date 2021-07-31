#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>

int main() {
  int64_t Q;
  std::cin >> Q;

  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t a, b;
    std::cin >> a;
    if (a == 1 || a == 2) {
      std::cin >> b;
      query.at(i) = std::make_pair(a, b);
    } else {
      query.at(i) = std::make_pair(a, 0);
    }
  }

  std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> heap;
  int64_t cumsum = 0;
  for (int64_t i = 0; i < Q; i++) {
    if (query.at(i).first == 1) {
      heap.push(query.at(i).second - cumsum);
    }
    if (query.at(i).first == 2) {
      cumsum += query.at(i).second;
    }
    if (query.at(i).first == 3) {
      std::cout << heap.top() + cumsum << std::endl;
      heap.pop();
    }
  }

  return 0;
}
