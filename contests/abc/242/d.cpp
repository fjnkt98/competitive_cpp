#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

char f(char c, int64_t ad) { return ('A' + (c - 'A' + ad) % 3); }

char g(std::string& S, int64_t t, int64_t k) {
  if (t == 0) return S.at(k);
  if (k == 0) return f(S.at(0), t);
  return f(g(S, t - 1, k / 2), k % 2 + 1);
}

int main() {
  std::string S;
  std::cin >> S;
  int64_t Q;
  std::cin >> Q;
  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t t, k;
    std::cin >> t >> k;
    query.at(i) = {t, k - 1};
  }

  for (int64_t i = 0; i < Q; i++) {
    auto [t, k] = query.at(i);
    std::cout << g(S, t, k) << std::endl;
  }

  return 0;
}
