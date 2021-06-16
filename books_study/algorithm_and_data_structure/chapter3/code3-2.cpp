/*
 * Linear Search Method
 *
 * Get index of the element that satisfies the
 * condition.
 */

#include <bits/stdint-intn.h>
#include <iostream>
#include <vector>

int main() {
  int64_t N;
  int64_t v;

  std::cin >> N >> v;

  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  int64_t found_id = -1;
  for (int64_t i = 0; i < N; i++) {
    if (a.at(i) == v) {
      found_id = i;
      break;
    }
  }

  std::cout << found_id << std::endl;

  return 0;
}
