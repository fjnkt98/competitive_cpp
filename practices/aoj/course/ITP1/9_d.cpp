#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string str;
  int64_t N;
  std::cin >> str;
  std::cin >> N;

  for (int64_t i = 0; i < N; i++) {
    std::string query;
    std::cin >> query;
    if (query == "replace") {
      int64_t a, b;
      std::string p;
      std::cin >> a >> b >> p;
      str.replace(a, b - a + 1, p);
    } else if (query == "reverse") {
      int64_t a, b;
      std::cin >> a >> b;
      std::string target_string = str.substr(a, b - a + 1);
      std::reverse(target_string.begin(), target_string.end());
      str.replace(a, b - a + 1, target_string);
    } else if (query == "print") {
      int64_t a, b;
      std::cin >> a >> b;
      std::cout << str.substr(a, (b - a + 1)) << std::endl;
    }
  }

  return 0;
}
