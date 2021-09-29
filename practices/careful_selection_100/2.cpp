/*
 * https://atcoder.jp/contests/abc106/tasks/abc106_b
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t count_divider(int64_t N) {
  int64_t count = 0;
  for (int64_t i = 1; i <= N; i++) {
    if (N % i == 0) {
      count++;
    }
  }

  return count;
}

int main() {
  int64_t N;
  std::cin >> N;

  int64_t count = 0;
  for (int64_t i = 1; i <= N; i++) {
    if (i % 2 == 1 && count_divider(i) == 8) {
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
