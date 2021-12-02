#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::string> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i);
  }

  std::vector<std::vector<int64_t>> count(N, std::vector<int64_t>(26, 0));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < static_cast<int64_t>(S.at(i).size()); j++) {
      count.at(i).at(static_cast<int64_t>(S.at(i).at(j) - 'a'))++;
    }
  }

  std::string answer = "";
  for (int64_t i = 0; i < 26; i++) {
    int64_t minimum_count = 1LL << 60;
    for (int64_t j = 0; j < N; j++) {
      minimum_count = std::min(minimum_count, count.at(j).at(i));
    }

    for (int64_t k = 0; k < minimum_count; k++) {
      answer.push_back(static_cast<char>('a' + i));
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
