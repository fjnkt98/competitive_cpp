#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int64_t> rolling_hash(std::string S, std::string T) {
  const int64_t B = 100000007;
  std::vector<int64_t> hit_place;

  if (S.size() < T.size()) return {};

  uint64_t t = 1;
  for (size_t i = 0; i < T.size(); i++) t *= B;

  uint64_t hashS = 0;
  uint64_t hashT = 0;
  for (size_t i = 0; i < T.size(); i++) {
    hashS = hashS * B + S.at(i);
  }
  for (size_t i = 0; i < T.size(); i++) {
    hashT = hashT * B + T.at(i);
  }

  for (size_t i = 0; i + T.size() <= S.size(); i++) {
    if (hashS == hashT) hit_place.push_back(i);
    if (i + T.size() < S.size()) {
      hashS = hashS * B + S.at(i + T.size()) - S.at(i) * t;
    }
  }

  return hit_place;
}

int main() {
  std::string T, P;
  std::cin >> T >> P;

  if (T.size() < P.size()) {
    return 0;
  }

  auto hit_place = rolling_hash(T, P);
  for (auto h : hit_place) {
    std::cout << h << std::endl;
  }

  return 0;
}
