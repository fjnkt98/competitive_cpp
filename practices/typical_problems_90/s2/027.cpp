#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::string> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i);
  }

  std::set<std::string> registered_users;
  for (int64_t i = 0; i < N; i++) {
    if (registered_users.find(S.at(i)) == registered_users.end()) {
      std::cout << i + 1 << std::endl;
    }
    registered_users.insert(S.at(i));
  }

  return 0;
}
