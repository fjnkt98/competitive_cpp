#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

int main() {
  std::string S;
  std::cin >> S;
  int64_t Q;
  std::cin >> Q;

  std::deque<char> answer;
  for (size_t i = 0; i < S.size(); i++) {
    answer.push_back(S.at(i));
  }

  bool fliped = false;
  for (int64_t i = 0; i < Q; i++) {
    int64_t T;
    std::cin >> T;
    if (T == 1) {
      fliped = !fliped;
    } else {
      int64_t F;
      char C;
      std::cin >> F >> C;

      if (F == 1) {
        if (fliped) {
          answer.push_back(C);
        } else {
          answer.push_front(C);
        }
      } else {
        if (fliped) {
          answer.push_front(C);
        } else {
          answer.push_back(C);
        }
      }
    }
  }

  if (fliped) std::reverse(answer.begin(), answer.end());
  for (size_t i = 0; i < answer.size(); i++) {
    std::cout << answer.at(i);
  }
  std::cout << std::endl;

  return 0;
}
