#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::map<std::string, int64_t> blue;
  std::map<std::string, int64_t> red;
  int64_t N;
  std::cin >> N;
  std::vector<std::string> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i);
    blue[S.at(i)]++;
  }
  int64_t M;
  std::cin >> M;
  std::vector<std::string> T(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> T.at(i);
    red[T.at(i)]++;
  }

  int64_t answer = 0;
  for (auto b : blue) {
    answer = std::max(answer, b.second - red[b.first]);
  }

  std::cout << answer << std::endl;

  return 0;
}