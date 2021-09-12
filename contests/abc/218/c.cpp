#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> trim(std::vector<std::string> X) {
  int64_t N = static_cast<int64_t>(X.size());
  int64_t min_r = 1LL << 60;
  int64_t max_r = 0;
  int64_t min_c = 1LL << 60;
  int64_t max_c = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      if (X.at(i).at(j) == '#') {
        min_r = std::min(min_r, i);
        max_r = std::max(max_r, i);
        min_c = std::min(min_c, j);
        max_c = std::max(max_c, j);
      }
    }
  }
  std::vector<std::string> trimed_X;
  for (int64_t i = min_r; i <= max_r; i++) {
    trimed_X.push_back(X.at(i).substr(min_c, max_c - min_c + 1));
  }

  return trimed_X;
}

std::vector<std::string> rotate(std::vector<std::string> X) {
  int64_t H = static_cast<int64_t>(X.size());
  int64_t W = static_cast<int64_t>(X.at(0).size());

  std::vector<std::string> x(W);
  for (int64_t i = 0; i < W; i++) {
    for (int64_t j = H - 1; j >= 0; j--) {
      x.at(i).push_back(X.at(j).at(i));
    }
  }

  return x;
}

bool is_same(std::vector<std::string> S, std::vector<std::string> T) {
  if (S.size() == T.size() && S.at(0).size() == T.at(0).size())
  {
    bool ok = true;
    for (size_t i = 0; i < S.size(); i++) {
      for (size_t j = 0; j < S.at(0).size(); j++) {
        if (S.at(i).at(j) != T.at(i).at(j)) ok = false;
      }
    }
    return ok;
  } else {
    return false;
  }
}

int main() {
  int64_t N;
  std::cin >> N;

  if (N == 1) {
    std::cout << "Yes" << std::endl;
    return 0;
  }

  std::vector<std::string> S(N);
  for (auto& s : S) {
    std::cin >> s;
  }
  std::vector<std::string> T(N);
  for (auto& t : T) {
    std::cin >> t;
  }

  auto s = trim(S);
  auto t = trim(T);

  bool ok = false;
  if ((s.size() == t.size() && s.at(0).size() == t.at(0).size())
      || (s.size() == t.at(0).size() && s.at(0).size() == t.size()))
  {
    for (int64_t i = 0; i < 4; i++) {
      t = rotate(t);
      if (is_same(s, t)) ok = true;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
