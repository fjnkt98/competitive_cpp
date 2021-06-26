#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> t(N);
  std::vector<int64_t> l(N);
  std::vector<int64_t> r(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> t.at(i) >> l.at(i) >> r.at(i);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      if (t.at(i) == 1) {
        if (t.at(j) == 1) {
          if ((l.at(i) <= l.at(j) && r.at(i) >= l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) <= r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 2) {
          if ((l.at(i) <= l.at(j) && r.at(i) >= l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 3) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) <= r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 4) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        }
      } else if (t.at(i) == 2) {
        if (t.at(j) == 1) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) <= r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 2) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 3) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) <= r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 4) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        }
      } else if (t.at(i) == 3) {
        if (t.at(j) == 1) {
          if ((l.at(i) <= l.at(j) && r.at(i) >= l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 2) {
          if ((l.at(i) <= l.at(j) && r.at(i) >= l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 3) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 4) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        }
      } else if (t.at(i) == 4) {
        if (t.at(j) == 1) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 2) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 3) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        } else if (t.at(j) == 4) {
          if ((l.at(i) <= l.at(j) && r.at(i) > l.at(j)) || (l.at(i) >= l.at(j) && l.at(i) < r.at(j))) {
            count++;
          }
        }
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}
