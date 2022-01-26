#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::string> S(N);
  std::map<std::string, int64_t> index;
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i);
    index[S.at(i)] = i;
  }
  std::vector<std::string> T(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> T.at(i);
  }

  std::vector<bool> is_arrive(N, false);
  is_arrive.at(0) = true;
  is_arrive.back() = true;

  for (int64_t i = 0; i < M; i++) {
    is_arrive.at(index[T.at(i)]) = true;
  }

  for (bool flag : is_arrive) {
    if (flag) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

  return 0;
}
