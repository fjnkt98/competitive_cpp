#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<std::string, std::string>> query(N);
  for (auto& q : query) {
    std::string command;
    std::string value;
    std::cin >> command >> value;
    q = std::make_pair(command, value);
  }

  std::set<std::string> s;
  for (auto& q : query) {
    if (q.first == "insert") {
      s.insert(q.second);
    }
    if (q.first == "find") {
      if (s.find(q.second) != s.end()) {
        std::cout << "yes" << std::endl;
      } else {
        std::cout << "no" << std::endl;
      }
    }
  }

  return 0;
}
