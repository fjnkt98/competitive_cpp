#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<std::string> array;
  while (true) {
    std::string x;
    std::cin >> x;
    if (x == "0") {
      break;
    } else {
      int64_t sum = 0;
      for (auto s : x) {
        sum += static_cast<int64_t>(s - '0');
      }

      std::cout << sum << std::endl;
    }
  }

  return 0;
}
