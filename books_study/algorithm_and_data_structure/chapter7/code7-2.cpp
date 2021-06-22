/*
 * Solving "Interval Scheduling Problem" by using Greedy Algorithm
 */

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int64_t, int64_t>& a, const std::pair<int64_t, int64_t>& b) {
  return (a.second < b.second);
}

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::pair<int64_t, int64_t>> interval(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> interval.at(i).first >> interval.at(i).second;
  }

  // Sort the interval in ascending order of end time
  std::sort(interval.begin(), interval.end(), compare);

  int64_t result = 0;
  int64_t current_end_time = 0;
  for (int64_t i = 0; i < N; i++) {
    if (interval.at(i).first < current_end_time) {
      continue;
    }

    result++;
    current_end_time = interval.at(i).second;
  }

  std::cout << result << std::endl;
}
