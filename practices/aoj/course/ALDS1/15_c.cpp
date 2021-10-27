#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<int64_t, int64_t>> segment(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t s, t;
    std::cin >> s >> t;

    segment.at(i) = std::make_pair(t, s);
  }

  std::sort(segment.begin(), segment.end());

  int64_t last_end_point = 0;
  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    if (segment.at(i).second > last_end_point) {
      count++;
      last_end_point = segment.at(i).first;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
