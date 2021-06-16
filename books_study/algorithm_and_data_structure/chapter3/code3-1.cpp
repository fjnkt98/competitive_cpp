/*
 * Linear Search Method
 *
 * Check if there is an element in the array
 * equal to the input value.
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

  bool exist = false;
  for (int64_t i = 0; i < N; i++) {
    if (a.at(i) == v) {
      exist = true;
    }
  }

  if (exist) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
