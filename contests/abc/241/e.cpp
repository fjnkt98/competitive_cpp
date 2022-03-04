#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> memo(N, -1);
  std::vector<int64_t> history;
  history.push_back(0);
  int64_t loop_start = -1;
  int64_t loop_end = -1;
  int64_t X = 0;
  int64_t incremental = 0;
  int64_t loop_size = 0;
  int64_t i = 1;
  while (i <= K) {
    if (memo.at(X % N) != -1) {
      incremental = (X + A.at(X % N) - history.at(memo.at(X % N)));
      loop_size = i - memo.at(X % N);
      break;
    } else {
      memo.at(X % N) = i;
      X += A.at(X % N);
      history.push_back(X);
    }
    i++;
  }

  if (i < K) {
    K -= i - 1;
    X += (K / loop_size) * incremental;
    K = K % loop_size;

    while (K) {
      X += A.at(X % N);
      K--;
    }
  }

  std::cout << X << std::endl;

  return 0;
}
