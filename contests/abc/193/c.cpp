#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t count = N;
  std::map<int64_t, int64_t> used_number;
  for (int64_t a = 2; a * a <= N; a++) {
    for (int64_t b = a * a; b <= N; b *= a) {
      if (b <= N && used_number[b] == 0) count--;
      used_number[b]++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
