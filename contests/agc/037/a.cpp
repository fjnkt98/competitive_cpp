#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  int64_t N = static_cast<int64_t>(S.size());

  // std::vector<std::pair<char, int64_t>> compressed_string;
  // char current_char = S.at(0);
  // int64_t current_count = 1;
  // for (int64_t i = 1; i < N; ++i) {
  //   if (S.at(i) == current_char) {
  //     ++current_count;
  //   } else {
  //     compressed_string.push_back({current_char, current_count});
  //     current_char = S.at(i);
  //     current_count = 1;
  //   }
  // }
  // compressed_string.push_back({current_char, current_count});

  // std::cout << compressed_string.size() << std::endl;
  // for (size_t i = 0; i < compressed_string.size(); ++i) {
  //   std::cout << compressed_string.at(i).first << " "
  //             << compressed_string.at(i).second << std::endl;
  // }

  int64_t answer = 1;
  char current_char = S.at(0);
  for (int64_t i = 1; i < N; i++) {
    if (S.at(i) == current_char) {
      current_char = 0;
      i++;
      if (i >= N) break;
    } else {
      current_char = S.at(i);
    }
    answer++;
  }

  std::cout << answer << std::endl;

  return 0;
}