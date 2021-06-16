/*
 * Seek minimum value in the array.
 */

#include <bits/stdint-intn.h>
#include <iostream>
#include <vector>
#include <climits>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  int64_t min_value = INT_MAX;
  for (int64_t i = 0; i < N; i++) {
    if (a.at(i) < min_value) {
      min_value = a.at(i);
    }
  }

  std::cout << min_value << std::endl;
  return 0;
}
