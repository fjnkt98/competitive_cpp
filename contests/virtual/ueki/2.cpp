#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

int main() {
  int64_t N, C;
  std::cin >> N >> C;
  std::vector<std::tuple<int64_t, int64_t, int64_t>> input(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b, c;
    std::cin >> a >> b >> c;
    input.at(i) = std::make_tuple(a, b, c);
  }

  std::vector<std::pair<int64_t, int64_t>> events;
  for (int64_t i = 0; i < N; i++) {
    int64_t a = std::get<0>(input.at(i));
    int64_t b = std::get<1>(input.at(i));
    int64_t c = std::get<2>(input.at(i));

    events.push_back(std::make_pair(a, c));
    events.push_back(std::make_pair(b + 1, -c));
  }

  std::sort(events.begin(), events.end());

  int64_t answer = 0;
  int64_t cost = 0;
  for (size_t i = 0; i < events.size() - 1; i++) {
    cost += events.at(i).second;
    answer += std::min(cost, C) * (events.at(i + 1).first - events.at(i).first);
  }

  std::cout << answer << std::endl;

  return 0;
}