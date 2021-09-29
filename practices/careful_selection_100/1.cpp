/*
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  bool ok = true;
  while (ok) {
    int64_t N, X;
    std::cin >> N >> X;

    if (N == 0 && X == 0) {
      ok = false;
      break;
    }

    int64_t count = 0;
    for (int64_t i = 1; i <= N; i++) {
      for (int64_t j = i + 1; j <= N; j++) {
        for (int64_t k = j + 1; k <= N; k++) {
          if (i + j + k == X) {
            count++;
          }
        }
      }
    }

    std::cout << count << std::endl;
  }

  return 0;
}
