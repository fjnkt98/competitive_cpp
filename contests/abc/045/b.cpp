#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
  std::string A, B, C;
  std::cin >> A >> B >> C;

  std::reverse(A.begin(), A.end());
  std::reverse(B.begin(), B.end());
  std::reverse(C.begin(), C.end());

  char current_turn = 'a';
  bool is_end = false;
  while (!is_end) {
    if (current_turn == 'a') {
      if (A.empty()) {
        break;
      }
      current_turn = A.back();
      A.pop_back();
    } else if (current_turn == 'b') {
      if (B.empty()) {
        break;
      }
      current_turn = B.back();
      B.pop_back();
    } else {
      if (C.empty()) {
        break;
      }
      current_turn = C.back();
      C.pop_back();
    }
  }

  std::cout << std::toupper(current_turn, std::locale::classic()) << std::endl;

  return 0;
}
