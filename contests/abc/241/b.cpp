#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> A(N);
  std::map<int64_t, int64_t> pasta;
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
    ++pasta[A.at(i)];
  }

  std::vector<int64_t> B(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> B.at(i);
  }

  bool ok = true;
  for (int64_t i = 0; i < M; i++) {
    if (pasta[B.at(i)] == 0) ok = false;

    --pasta[B.at(i)];
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
