#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  std::string S;
  std::cin >> S;

  std::map<char, int64_t> count;
  for (char c : S) {
    count[c]++;
  }

  std::string T;
  for (auto c : count) {
    if (c.second <= 3) {
      for (int64_t i = 0; i < c.second; i++) {
        T.push_back(c.first);
      }
    } else {
      for (int64_t i = 0; i < 3; i++) {
        T.push_back(c.first);
      }
    }
  }

  bool ok = false;

  if (T.size() < 3) {
    std::string U;
    for (auto t : T) {
      U.push_back(t);
    }

    do {
      int64_t X = std::stol(U);
      if (X % 8 == 0) {
        ok = true;
      }
    } while (std::next_permutation(U.begin(),U.end()));

  } else {
    for (size_t i = 0; i < T.size(); i++) {
      for (size_t j = i + 1; j < T.size(); j++) {
        for (size_t k = j + 1; k < T.size(); k++) {
          std::string U;
          U.push_back(T.at(i));
          U.push_back(T.at(j));
          U.push_back(T.at(k));
          std::sort(U.begin(), U.end());

          do {
            int64_t X = std::stol(U);
            if (X % 8 == 0) {
              ok = true;
            }
          } while (std::next_permutation(U.begin(), U.end()));
        }
      }
    }
  }


  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
