#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<int64_t, int64_t>> X;
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    X.push_back(std::make_pair(a, 1));
    X.push_back(std::make_pair(a + b, -1));
  }

  std::sort(X.begin(), X.end());

  std::vector<int64_t> answer(N + 1, 0);
  int64_t count = 0;
  for (int64_t i = 0; i < static_cast<int64_t>(X.size()) - 1; i++) {
    count += X.at(i).second;
    answer.at(count) += X.at(i + 1).first - X.at(i).first;
  }

  for (int64_t i = 1; i <= N; i++) {
    if (i != 1) std::cout << " ";
    std::cout << answer.at(i);
  }
  std::cout << std::endl;

  return 0;
}
