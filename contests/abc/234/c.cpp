#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t K;
  std::cin >> K;

  std::bitset<64> bin(K);
  std::string S = bin.to_string();

  auto iter = std::find(S.begin(), S.end(), '1');
  std::string answer = S.substr(std::distance(S.begin(), iter));

  for (char& c : answer) {
    c = c == '0' ? '0' : '2';
  }

  std::cout << answer << std::endl;

  return 0;
}
