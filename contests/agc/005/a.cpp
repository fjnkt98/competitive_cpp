#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
  std::string X;
  std::cin >> X;

  int64_t N = static_cast<int64_t>(X.size());

  std::stack<char> stack;
  for (int64_t i = 0; i < N; i++) {
    if (X.at(i) == 'S') {
      stack.push(X.at(i));
    } else {
      if (!stack.empty() && stack.top() == 'S') {
        stack.pop();
      } else {
        stack.push(X.at(i));
      }
    }
  }

  std::cout << stack.size() << std::endl;

  return 0;
}