/*
 * https://atcoder.jp/contests/abc150/tasks/abc150_c
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> P(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> P.at(i);
  }
  std::vector<int64_t> Q(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> Q.at(i);
  }

  std::vector<int64_t> R(N);
  std::copy(P.begin(), P.end(), R.begin());
  std::sort(R.begin(), R.end());

  int64_t a = 0;
  int64_t b = 0;
  int64_t count = 1;
  do {
    if (R == P) {
      a = count;
    }
    if (R == Q) {
      b = count;
    }
    count++;
  } while (std::next_permutation(R.begin(), R.end()));

  std::cout << std::abs(a - b) << std::endl;

  return 0;
}
