#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;

  int64_t A = static_cast<int64_t>(S.at(0) - '0');
  int64_t B = static_cast<int64_t>(S.at(1) - '0');
  int64_t C = static_cast<int64_t>(S.at(2) - '0');
  int64_t D = static_cast<int64_t>(S.at(3) - '0');

  std::string op = "+-";
  std::string answer = "AxBxCxD=7";
  answer.at(0) = S.at(0);
  answer.at(2) = S.at(1);
  answer.at(4) = S.at(2);
  answer.at(6) = S.at(3);
  for (int64_t i = 0; i < 2; i++) {
    for (int64_t j = 0; j < 2; j++) {
      for (int64_t k = 0; k < 2; k++) {
        int64_t result = A;

        result += op.at(i) == '+' ? B : -B;
        result += op.at(j) == '+' ? C : -C;
        result += op.at(k) == '+' ? D : -D;

        if (result == 7) {
          answer.at(1) = op.at(i);
          answer.at(3) = op.at(j);
          answer.at(5) = op.at(k);
        }
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
