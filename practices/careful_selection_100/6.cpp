/*
 * https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  int64_t N;
  std::string S;
  std::cin >> N >> S;

  int64_t count = 0;
  for (int64_t i = 0; i < 1000; i++) {
    std::string pin = std::to_string(i);
    while (pin.size() < 3) pin = "0" + pin;

    bool ok = true;
    int64_t index = 0;
    for (int64_t i = 0; i < 3; i++) {
      ok = false;
      for (int64_t j = index; j < N; j++) {
        if (pin.at(i) == S.at(j)) {
          index = j + 1;
          ok = true;
          break;
        }
      }
      if (!ok) break;
    }

    if (ok) count++;
  }

  std::cout << count << std::endl;

  return 0;
}
