#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
  int64_t a, N;
  std::cin >> a >> N;

  int64_t M = 1;
  while (M <= N) {
    M *= 10;
  }

  std::vector<int64_t> distance(M, -1);
  std::queue<int64_t> candidate;
  distance.at(1) = 0;
  candidate.push(1);

  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    int64_t operation1 = a * node;
    if (operation1 < M && distance.at(operation1) == -1) {
      distance.at(operation1) = distance.at(node) + 1;
      candidate.push(operation1);
    }

    if (node >= 10 && node % 10 != 0) {
      std::string S = std::to_string(node);

      int64_t operation2 = std::stoll(S.back() + S.substr(0, S.size() - 1));

      if (operation2 < M && distance.at(operation2) == -1) {
        distance.at(operation2) = distance.at(node) + 1;
        candidate.push(operation2);
      }
    }
  }

  std::cout << distance.at(N) << std::endl;

  return 0;
}
