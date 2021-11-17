#include <bits/stdint-intn.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> D(N);
  std::map<int64_t, int64_t> problem_count;
  for (int64_t i = 0; i < N; i++) {
    std::cin >> D.at(i);
    problem_count[D.at(i)]++;
  }
  int64_t M;
  std::cin >> M;
  std::vector<int64_t> T(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> T.at(i);
  }

  bool ok = true;
  for (int64_t i = 0; i < M; i++) {
    if (problem_count[T.at(i)] != 0) {
      problem_count[T.at(i)]--;
    } else {
      ok = false;
    }
  }

  if (ok) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;

  return 0;
}
