#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::string> S(N);
  std::vector<int64_t> count(5);
  for (int64_t i = 0; i < N; i++) {
    std::string s;
    std::cin >> s;

    S.at(i) = s;
    switch (s.at(0)) {
      case 'M':
        count.at(0)++;
        break;
      case 'A':
        count.at(1)++;
        break;

      case 'R':
        count.at(2)++;
        break;
      case 'C':
        count.at(3)++;
        break;
      case 'H':
        count.at(4)++;
        break;
    }
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < 5; i++) {
    for (int64_t j = i + 1; j < 5; j++) {
      for (int64_t k = j + 1; k < 5; k++) {
        answer += count.at(i) * count.at(j) * count.at(k);
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
