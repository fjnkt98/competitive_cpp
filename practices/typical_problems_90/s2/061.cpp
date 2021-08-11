#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

int main() {
  int64_t Q;
  std::cin >> Q;
  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t t, x;
    std::cin >> t >> x;
    query.at(i) = std::make_pair(t, x);
  }

  std::deque<int64_t> deck;
  for (int64_t i = 0; i < Q; i++) {
    switch (query.at(i).first) {
      case 1:
        deck.push_front(query.at(i).second);
        break;
      case 2:
        deck.push_back(query.at(i).second);
        break;
      case 3:
        std::cout << deck.at(query.at(i).second - 1) << std::endl;
        break;
    }
  }

  return 0;
}
