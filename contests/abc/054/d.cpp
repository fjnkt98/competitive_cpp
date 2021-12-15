#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

int main() {
  int64_t N, Ma, Mb;
  std::cin >> N >> Ma >> Mb;

  std::vector<std::tuple<int64_t, int64_t, int64_t>> input(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b, c;
    std::cin >> a >> b >> c;
    input.at(i) = std::make_tuple(a, b, c);
  }


  return 0;
}
