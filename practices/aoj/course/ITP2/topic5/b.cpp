#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::tuple<int64_t, int64_t, std::string, int64_t, std::string>> A(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t v, w, d;
    std::string t, s;
    std::cin >> v >> w >> t >> d >> s;

    A.at(i) = std::make_tuple(v, w, t, d, s);
  }

  std::sort(A.begin(), A.end());

  for (int64_t i = 0; i < N; i++) {
    std::cout <<
      std::get<0>(A.at(i)) << " " <<
      std::get<1>(A.at(i)) << " " <<
      std::get<2>(A.at(i)) << " " <<
      std::get<3>(A.at(i)) << " " <<
      std::get<4>(A.at(i)) <<
    std::endl;
  }

  return 0;
}
