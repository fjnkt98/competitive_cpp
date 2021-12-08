#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t left = 0;
  int64_t right = N;

  while (right - left > 1) {
    int64_t mid = (right + left) / 2;

    int64_t sum = (mid + 1) * mid / 2;

    if (sum >= N) {
      right = mid;
    } else {
      left = mid;
    }
  }

  std::vector<int64_t> answer;
  while (N > 0) {
    N -= right;
    answer.push_back(right);

    right--;

    if (N <= right) {
      answer.push_back(N);
      break;
    }
  }

  for (auto a : answer) {
    if (a == 0) continue;
    std::cout << a << std::endl;
  }

  return 0;
}
