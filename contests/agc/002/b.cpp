#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> X(M);
  std::vector<int64_t> Y(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> X.at(i) >> Y.at(i);

    X.at(i)--;
    Y.at(i)--;
  }

  std::vector<int64_t> count(N, 1);
  std::vector<bool> ok(N, false);
  ok.at(0) = true;

  for (int64_t i = 0; i < M; i++) {
    if (ok.at(X.at(i))) {
      ok.at(Y.at(i)) = true;
    }

    count.at(X.at(i))--;
    count.at(Y.at(i))++;

    if (count.at(X.at(i)) == 0) {
      ok.at(X.at(i)) = false;
    }
  }

  std::cout << std::count(ok.begin(), ok.end(), true) << std::endl;

  return 0;
}
