#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool judge(std::string array) {
  int64_t depth = 0;
  for (auto& c : array) {
    if (c == '(') {
      depth++;
    } else if (c == ')') {
      depth--;
    }
    if (depth < 0) {
      return false;
    }
  }
  if (depth == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int64_t N;
  std::cin >> N;

  for (int64_t i = 0; i < (1LL << N); i++) {
    std::string parentheses_array = "";
    for (int64_t j = N - 1; j >= 0; j--) {
      if ((i & (1 << j)) == 0) {
        parentheses_array += "(";
      } else {
        parentheses_array += ")";
      }
    }

    if (judge(parentheses_array)) {
      std::cout << parentheses_array << std::endl;
    }
  }

  return 0;
}
