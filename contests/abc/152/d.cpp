#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::vector<int64_t>> count(10, std::vector<int64_t>(10));
  for (int64_t i = 1; i <= N; i++) {
    std::string S = std::to_string(i);

    int64_t top = static_cast<int64_t>(S.at(0) - '0');
    int64_t bottom = static_cast<int64_t>(S.back() - '0');

    count.at(top).at(bottom) += 1;
  }

  int64_t answer = 0;
  for (int64_t i = 1; i < 10; i++) {
    for (int64_t j = 1; j < 10; j++) {
      answer += count.at(i).at(j) * count.at(j).at(i);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}