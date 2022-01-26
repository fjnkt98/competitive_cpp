#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int64_t search(std::vector<std::vector<int64_t>>& A,
               std::vector<std::pair<int64_t, int64_t>>& pair,
               std::vector<bool>& used, int64_t N) {
  if (pair.size() >= N) {
    int64_t result = 0;
    for (auto p : pair) {
      result ^= (A.at(p.first).at(p.second));
    }

    return result;
  }

  int64_t first = 0;
  for (int64_t i = 0; i < 2 * N; i++) {
    if (!used.at(i)) {
      first = i;
      break;
    }
  }
  used.at(first) = true;

  int64_t result = 0;
  for (int64_t i = 0; i < 2 * N; i++) {
    if (!used.at(i)) {
      pair.push_back(std::make_pair(first, i));
      used.at(i) = true;

      result = std::max(result, search(A, pair, used, N));

      pair.pop_back();
      used.at(i) = false;
    }
  }

  used.at(first) = false;

  return result;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> A(2 * N, std::vector<int64_t>(2 * N));
  for (int64_t i = 0; i < 2 * N - 1; i++) {
    for (int64_t j = i + 1; j < 2 * N; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  std::vector<std::pair<int64_t, int64_t>> pair;
  std::vector<bool> used(2 * N, false);

  std::cout << search(A, pair, used, N) << std::endl;

  return 0;
}
