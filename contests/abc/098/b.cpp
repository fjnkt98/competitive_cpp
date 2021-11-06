#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  int64_t answer = 0;
  for (int64_t i = 1; i < N; i++) {
    std::string X = S.substr(0, i);
    std::string Y = S.substr(i);

    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());
    X.erase(std::unique(X.begin(), X.end()), X.end());
    Y.erase(std::unique(Y.begin(), Y.end()), Y.end());

    std::map<char, int64_t> count;
    for (size_t j = 0; j < X.size(); j++) {
      count[X.at(j)]++;
    }
    for (size_t j = 0; j < Y.size(); j++) {
      count[Y.at(j)]++;
    }

    int64_t local_count = 0;
    for (auto c : count) {
      if (c.second >= 2) {
        local_count++;
      }
    }

    answer = std::max(answer, local_count);
  }

  std::cout << answer << std::endl;

  return 0;
}
