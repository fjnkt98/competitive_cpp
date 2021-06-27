#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> t(N);
  std::vector<int64_t> l(N);
  std::vector<int64_t> r(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t ti, li, ri;
    std::cin >> ti >> li >> ri;

    switch (ti) {
      case 1:
        l.at(i) = li * 2;
        r.at(i) = ri * 2 + 1;
        break;
      case 2:
        l.at(i) = li * 2;
        r.at(i) = ri * 2;
        break;
      case 3:
        l.at(i) = li * 2 + 1;
        r.at(i) = ri * 2 + 1;
        break;
      case 4:
        l.at(i) = li * 2 + 1;
        r.at(i) = ri * 2;
        break;
    }
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      if (std::max(l.at(i), l.at(j)) < std::min(r.at(i), r.at(j))) {
        count++;
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}
