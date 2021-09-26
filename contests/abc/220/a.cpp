#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C;
  std::cin >> A >> B >> C;

  int64_t answer = 0;
  bool ok = false;
  while (answer <= B) {
    answer += C;
    if (answer >= A && answer <= B) {
      ok = true;
      break;
    }
  }

  if (ok) {
    std::cout << answer << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }

  return 0;
}
