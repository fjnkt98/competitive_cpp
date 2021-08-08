#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

int main() {
  std::string s;
  std::cin >> s;

  std::stack<int64_t> slopes;
  std::vector<std::pair<int64_t, int64_t>> partial_ponds;
  int64_t sum_area = 0;
  for (size_t i = 0; i < s.size(); i++) {
    if (s.at(i) == '\\') {
      slopes.push(i);
    }
    if (s.at(i) == '/' && !slopes.empty()) {
      int64_t local_area = i - slopes.top();

      sum_area += local_area;

      while (!partial_ponds.empty() &&
              slopes.top() < partial_ponds.back().first) {
        local_area += partial_ponds.back().second;
        partial_ponds.pop_back();
      }

      partial_ponds.push_back(std::make_pair(slopes.top(), local_area));
      slopes.pop();
    }
  }

  std::cout << sum_area << std::endl;
  std::cout << partial_ponds.size();
  for (auto& p : partial_ponds) {
    std::cout << " " << p.second;
  }
  std::cout << std::endl;

  return 0;
}
