#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, C;
  std::cin >> N >> C;
  std::vector<int64_t> a(N);
  std::vector<int64_t> b(N);
  std::vector<int64_t> c(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i) >> b.at(i) >> c.at(i);
  }

  std::vector<std::pair<int64_t, int64_t>> X;
  for (int64_t i = 0; i < N; i++) {
    X.push_back(std::make_pair(a.at(i), c.at(i)));
    X.push_back(std::make_pair(b.at(i) + 1, -c.at(i)));
  }
  std::sort(X.begin(), X.end());

  int64_t answer = 0;
  int64_t fee = 0;
  for (int64_t i = 0; i < static_cast<int64_t>(X.size()) - 1; i++) {
    fee += X.at(i).second;
    answer += std::min(C, fee) * (X.at(i + 1).first - X.at(i).first);
  }

  std::cout << answer << std::endl;

  return 0;
}
