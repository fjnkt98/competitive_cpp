/*
 * AtCoder Beginner Contest 023 D - Shoot King
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

int main() {
  // Receive input
  uint64_t N;
  std::cin >> N;

  std::vector<uint64_t> h(N);
  std::vector<uint64_t> s(N);
  
  for (uint64_t i = 0; i < N; i++) {
    std::cin >> h.at(i) >> s.at(i);
  }

  // Binary search
  uint64_t left = 0;
  uint64_t right = UINT64_MAX;

  while (right - left > 1) {
    uint64_t mid = (left + right) / 2;

    // Judgement
    bool satisfied = true;

    // Time limit to break each balloon
    std::vector<uint64_t> time_limit(N, 0);
    for (uint64_t i = 0; i < N; i++) {
      if (mid < h.at(i)) { // false if mid is less than initial height
        satisfied = false;
      } else {
        time_limit.at(i) = (mid - h.at(i)) / s.at(i); // Time for i-th balloon to reach the height
      }
    }

    // Sort by earlist time limit
    std::sort(time_limit.begin(), time_limit.end());
    
    for (uint64_t i = 0; i < N; i++) {
      if (time_limit.at(i) < i) {
        satisfied = false;
      }
    }

    if (satisfied) {
      right = mid;
    } else {
      left = mid;
    }
  }

  std::cout << right << std::endl;
}
