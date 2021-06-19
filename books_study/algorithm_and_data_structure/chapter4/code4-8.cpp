/*
 * Fibonacci Number
 *
 * Calculate fibonacci by recursive function with memo.
 */

#include <iostream>
#include <vector>

std::vector<int64_t> memo;

int64_t fibo(int64_t N) {
  // Base cases
  if (N == 0) {
    return 0;
  }
  if (N == 1) {
    return 1;
  }

  // Check the memo
  if (memo.at(N) != -1) {
    return memo.at(N);
  }

  return memo.at(N) = fibo(N - 1) + fibo(N - 2);
}

int main() {
  memo.assign(50, -1);

  fibo(49);

  for (int64_t i = 2; i < 50; i++) {
    std:: cout << i << "nd index = " << memo.at(i) << std::endl;
  }
}
