#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  while (true) {
    std::string initial_string;
    int64_t m;
    std::cin >> initial_string;
    if (initial_string == "-") {
      break;
    }
    std::cin >> m;

    std::vector<int64_t> h(m);
    for (int64_t i = 0; i < m; i++) {
      std::cin >> h.at(i);
    }

    std::string answer = initial_string;
    for (int64_t i = 0; i < m; i++) {
      answer = answer.substr(h.at(i)) + answer.substr(0, h.at(i));
    }

    std::cout << answer << std::endl;
  }

  return 0;
}
