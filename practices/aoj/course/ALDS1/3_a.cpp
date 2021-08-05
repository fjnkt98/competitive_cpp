#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cctype>

int main() {
  std::vector<std::string> equation;
  std::string input;
  while (std::cin >> input) {
    equation.push_back(input);
  }

  std::stack<int64_t> s;  

  for (std::string op : equation) {
    if (op == "+") {
      int64_t a = s.top();
      s.pop();
      int64_t b = s.top();
      s.pop();
      int64_t answer = a + b;
      s.push(answer);
    } else if (op == "-") {
      int64_t a = s.top();
      s.pop();
      int64_t b = s.top();
      s.pop();
      int64_t answer = b - a;
      s.push(answer);
    } else if (op == "*") {
      int64_t a = s.top();
      s.pop();
      int64_t b = s.top();
      s.pop();
      int64_t answer = a * b;
      s.push(answer);
    } else {
      s.push(std::stoi(op));
    }
  }

  std::cout << s.top() << std::endl;

  return 0;
}