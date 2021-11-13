#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    bool ok = false;

    for (int64_t a = 1; a <= 2000; a++) {
      for (int64_t b = 1; b <= 2000; b++) {
        if (S.at(i) == 4 * a * b + 3 * a + 3 * b)  {
          ok = true;
        }
      }
    }

    if (!ok) count++;
  }

  std::cout << count << std::endl;

  return 0;
}
