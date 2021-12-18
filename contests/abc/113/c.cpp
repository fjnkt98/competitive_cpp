#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::tuple<int64_t, int64_t, int64_t>> PY(M);
  for (int64_t i = 0; i < M; i++) {
    int64_t p, y;
    std::cin >> p >> y;

    PY.at(i) = std::make_tuple(i + 1, p, y);
  }

  std::vector<std::vector<std::tuple<int64_t, int64_t>>> P(N + 1);
  for (int64_t i = 0; i < M; i++) {
    int64_t index = std::get<0>(PY.at(i));
    int64_t p = std::get<1>(PY.at(i));
    int64_t y = std::get<2>(PY.at(i));

    P.at(p).push_back(std::make_tuple(y, index));
  }

  for (auto& p : P) {
    std::sort(p.begin(), p.end());
  }

  std::vector<std::string> number(M);
  for (int64_t i = 1; i <= N; i++) {
    if (P.at(i).empty()) continue;

    for (size_t j = 0; j < P.at(i).size(); j++) {
      int64_t index = std::get<1>(P.at(i).at(j));

      std::string first6 = std::to_string(i);
      while (first6.size() < 6) first6 = "0" + first6;

      std::string second6 = std::to_string(j + 1);
      while (second6.size() < 6) second6 = "0" + second6;

      number.at(index - 1) = first6 + second6;
    }
  }

  for (auto n : number) {
    std::cout << n << std::endl;
  }

  return 0;
}
