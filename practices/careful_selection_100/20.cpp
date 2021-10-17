/*
 * https://atcoder.jp/contests/abc077/tasks/arc084_a
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }
  std::vector<int64_t> C(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> C.at(i);
  }

  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  std::sort(C.begin(), C.end());

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    int64_t top = std::lower_bound(A.begin(), A.end(), B.at(i)) - A.begin();
    int64_t bottom = C.end() - std::upper_bound(C.begin(), C.end(), B.at(i));

    /* count += (top + 1) * bottom; */
    count += top * bottom;
  }

  std::cout << count << std::endl;

  return 0;
}
