#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S, T;
  std::cin >> S >> T;

  if (S.size() < T.size()) {
    std::cout << "UNRESTORABLE" << std::endl;
    return 0;
  }

  std::vector<int64_t> index;

  bool restorable = false;
  for (size_t i = 0; i < S.size() - T.size() + 1; i++) {
    bool ok = true;
    for (size_t j = 0; j < T.size(); j++) {
      if (S.at(i + j) == '?') continue;

      if (S.at(i + j) != T.at(j)) {
        ok = false;
      }
    }

    if (ok) {
      restorable = true;
      index.push_back(i);
    }
  }

  if (restorable == false) {
    std::cout << "UNRESTORABLE" << std::endl;
  } else {
    std::string answer = S;

    for (size_t i = 0; i < S.size(); i++) {
      if (answer.at(i) == '?') {
        answer.at(i) = 'a';
      }
    }
    for (size_t i = 0; i < T.size(); i++) {
      answer.at(index.at(0) + i) = T.at(i);
    }

    for (size_t i = 1; i < index.size(); i++) {
      std::string candidate = S;

      for (size_t j = 0; j < candidate.size(); j++) {
        if (candidate.at(j) == '?') {
          candidate.at(j) = 'a';
        }
      }
      for (size_t j = 0; j < T.size(); j++) {
        candidate.at(index.at(i) + j) = T.at(j);
      }

      answer = std::min(answer, candidate);
    }

    std::cout << answer << std::endl;
  }

  return 0;
}
