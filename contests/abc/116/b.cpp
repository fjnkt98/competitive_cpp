#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  int64_t s;
  std::cin >> s;

  std::vector<int64_t> a;
  std::set<int64_t> seen;
  int64_t answer = 0;
  int64_t i = 2;
  a.push_back(s);
  seen.insert(s);
  while (true) {
    if (s % 2 == 0) {
      s /= 2;
    } else {
      s = 3 * s + 1;
    }

    a.push_back(s);
    if (seen.find(s) != seen.end()) {
      answer = i;
      break;
    } else {
      seen.insert(s);
    }
    i++;
  }

  std::cout << answer << std::endl;

  return 0;
}
