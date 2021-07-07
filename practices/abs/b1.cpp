#include <iostream>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  int64_t count = 0;
  bool ok = true;
  while (ok) {
    for (int64_t i = 0; i < N; i++) {
      if (a.at(i) % 2 == 1) {
        ok = false;
      }
    }

    if (ok) {
      for (int64_t i = 0; i < N; i++) {
        a.at(i) /= 2;
      }

      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
