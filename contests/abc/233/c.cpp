#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<int64_t>>& A,
            int64_t X,
            int64_t index,
            int64_t product,
            int64_t& count)
{
  int64_t N = A.size();
  if (index >= N) {
    if (product == X) {
      count++;
    }
    return;
  }

  for (int64_t a : A.at(index)) {
    if (product > X / a) {
      continue;
    }

    dfs(A, X, index + 1, product * a, count);
  }
}

int main() {
  int64_t N, X;
  std::cin >> N >> X;
  std::vector<std::vector<int64_t>> A(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t L;
    std::cin >> L;
    for (int64_t j = 0; j < L; j++) {
      int64_t a;
      std::cin >> a;
      A.at(i).push_back(a);
    }
  }

  int64_t answer = 0;
  dfs(A, X, 0, 1, answer);

  std::cout << answer << std::endl;

  return 0;
}
