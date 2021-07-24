#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  std::string S1, S2, S3, S4;
  std::cin >> S1 >> S2 >> S3 >> S4;

  std::set<std::string> s;
  s.insert(S1);
  s.insert(S2);
  s.insert(S3);
  s.insert(S4);

  if (s.size() == 4) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
