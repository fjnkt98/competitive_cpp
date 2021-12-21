#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> takahashi(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b;
    std::cin >> a >> b;

    takahashi.at(a - 1).push_back(b - 1);
    takahashi.at(b - 1).push_back(a - 1);
  }

  std::vector<std::vector<int64_t>> aoki(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t c, d;
    std::cin >> c >> d;

    aoki.at(c - 1).push_back(d - 1);
    aoki.at(d - 1).push_back(c - 1);
  }

  std::vector<int64_t> P(N);
  std::iota(P.begin(), P.end(), 0);

  bool ok = false;
  do {
    bool is_same = true;
    for (int64_t i = 0; i < N; i++) {
      for (int64_t j = i + 1; j < N; j++) {
        if ((std::find(takahashi.at(i).begin(), takahashi.at(i).end(), j) == takahashi.at(i).end())
            ^ (std::find(aoki.at(P.at(i)).begin(), aoki.at(P.at(i)).end(), P.at(j)) == aoki.at(P.at(i)).end()))
        {
          is_same = false;
        }
      }
    }

    if (is_same) ok = true;
  } while (std::next_permutation(P.begin(), P.end()));

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
