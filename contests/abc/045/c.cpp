#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  int64_t N = static_cast<int64_t>(S.size());

  int64_t answer = 0;
  for (int64_t bit = 0; bit < (1 << (N - 1)); bit++) {
    int64_t sum = 0;

    std::string operand = "";
    operand.push_back(S.at(0));

    for (int64_t i = 0; i < N - 1; i++) {
      if (bit & (1 << i)) {
        sum += std::stoll(operand);
        operand = S.at(i + 1);
      } else {
        operand.push_back(S.at(i + 1));
      }
    }

    sum += std::stoll(operand);

    answer += sum;;
  }

  std::cout << answer << std::endl;

  return 0;
}
