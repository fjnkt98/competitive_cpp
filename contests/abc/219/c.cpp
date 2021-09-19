#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  std::string X;
  int64_t N;
  std::cin >> X >> N;

  std::vector<std::pair<std::string, std::string>> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::string s;
    std::cin >> s;
    S.at(i) = std::make_pair(s, s);
  }

  std::map<char, char> order;
  for (size_t i = 0; i < X.size(); i++) {
    order[X.at(i)] = static_cast<char>(i + '0');
  }

  for (size_t i = 0; i < S.size(); i++) {
    for (char& c : S.at(i).first) {
      c = order[c];
    }
  }

  std::sort(S.begin(), S.end());

  for (auto& s : S) {
    std::cout << s.second << std::endl;
  }

  return 0;
}
