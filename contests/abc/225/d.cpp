#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::vector<std::pair<int64_t, int64_t>> connection(N + 1, std::make_pair(-1, -1));
  for (int64_t i = 0; i < Q; i++) {
    int64_t t;
    std::cin >> t;
    if (t == 1) {
      int64_t x = 0;
      int64_t y = 0;
      std::cin >> x >> y;
      connection.at(x).second = y;
      connection.at(y).first = x;
    } else if (t == 2) {
      int64_t x = 0;
      int64_t y = 0;
      std::cin >> x >> y;
      connection.at(x).second = -1;
      connection.at(y).first = -1;
    } else if (t == 3) {
      int64_t x = 0;
      std::cin >> x;

      while (connection.at(x).first != -1) {
        x = connection.at(x).first;
      }
      std::vector<int64_t> answer;
      while (x != -1) {
        answer.push_back(x);
        x = connection.at(x).second;
      }

      std::cout << answer.size() << " ";
      for (size_t i = 0; i < answer.size(); i++) {
        if (i) std::cout << " ";
        std::cout << answer.at(i);
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
