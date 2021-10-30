#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  std::sort(S.begin(), S.end());

  int64_t count = 0;
  do {
    count++;
  } while (std::next_permutation(S.begin(), S.end()));

  std::cout << count << std::endl;

  return 0;
}
