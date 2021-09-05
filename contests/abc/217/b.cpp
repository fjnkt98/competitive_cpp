#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  std::set<std::string> contest;
  contest.insert("ABC");
  contest.insert("ARC");
  contest.insert("AGC");
  contest.insert("AHC");

  std::string S1, S2, S3;
  std::cin >> S1 >> S2 >> S3;

  contest.erase(S1);
  contest.erase(S2);
  contest.erase(S3);

  std::cout << *contest.begin() << std::endl;

  return 0;
}
