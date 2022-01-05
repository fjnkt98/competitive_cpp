#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void dfs(std::vector<int64_t>& A, int64_t i, int64_t prod, int64_t& answer) {
  if (i == A.size()) {
    if (prod % 2 == 0) {
      answer++;
    }
    return;
  }

  dfs(A, i + 1, prod * (A.at(i) - 1), answer);
  dfs(A, i + 1, prod * (A.at(i)), answer);
  dfs(A, i + 1, prod * (A.at(i) + 1), answer);
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t answer = 0;
  dfs(A, 0, 1, answer);

  std::cout << answer << std::endl;

  return 0;
}