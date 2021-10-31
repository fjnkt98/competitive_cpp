#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class RollingHash {
  public:
    RollingHash(std::string S, std::string T, uint64_t base = 1000000007)
      :S(S), T(T), base(base)
    {
      t = 1;
      for (size_t i = 0; i < T.size(); i++) {
        t *= base;
      }
    }

    // Determine if the string T is contianed in the string S.
    bool contain() {
      if (S.size() < T.size()) return false;

      uint64_t hashS = 0;
      uint64_t hashT = 0;

      // Calculate hash of substring of S
      for (size_t i = 0; i < T.size(); i++) {
        hashS = hashS * base + S.at(i);
      }

      // Calculate hash of T
      for (size_t i = 0; i < T.size(); i++) {
        hashT = hashT * base + T.at(i);
      }

      // Search
      for (size_t i = 0; i + T.size() <= S.size(); i++) {
        if (hashS == hashT) return true;
        if (i + T.size() < S.size()) {
          hashS = hashS * base + S.at(i + T.size()) - S.at(i) * t;
        }
      }

      return false;
    }

    // Enumerate the start of the part of the string S that matches the string T.
    std::vector<int64_t> match_place() {
      if (S.size() < T.size()) return {};

      std::vector<int64_t> match_place;

      uint64_t hashS = 0;
      uint64_t hashT = 0;

      // Calculate hash of substring of S
      for (size_t i = 0; i < T.size(); i++) {
        hashS = hashS * base + S.at(i);
      }

      // Calculate hash of T
      for (size_t i = 0; i < T.size(); i++) {
        hashT = hashT * base + T.at(i);
      }

      // Search
      for (size_t i = 0; i + T.size() <= S.size(); i++) {
        if (hashS == hashT) match_place.push_back(i);
        if (i + T.size() < S.size()) {
          hashS = hashS * base + S.at(i + T.size()) - S.at(i) * t;
        }
      }

      return match_place;
    }

  private:
    std::string S;
    std::string T;
    uint64_t base;
    uint64_t t;
};

int main() {
  std::string T, P;
  std::cin >> T >> P;

  RollingHash rh(T, P);

  auto match_place = rh.match_place();
  for (auto m : match_place) {
    std::cout << m << std::endl;
  }

  return 0;
}
