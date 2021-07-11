#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<std::vector<int64_t>> points;
  int64_t count = 0;
  for (int64_t i = 0; i < 50; i++) {
    int64_t m, f, r;
    std::cin >> m >> f >> r;
    if (m == -1 && f == -1 && r == -1) {
      break;
    } else {
      std::vector<int64_t> point = {m, f, r};
      points.push_back(point);
      count++;
    }
  }

  std::vector<std::string> grade(count);
  for (int64_t i = 0; i < count; i++) {
    if (points.at(i).at(0) == -1 || points.at(i).at(1) == -1) {
      grade.at(i) = "F";
    } else {
      int64_t sum = points.at(i).at(0) + points.at(i).at(1);

      if (sum >= 80) {
        grade.at(i) = "A";
      } else if (sum >= 65) {
        grade.at(i) = "B";
      } else if (sum >= 50) {
        grade.at(i) = "C";
      } else if (sum >= 30) {
        if (points.at(i).at(2) >= 50) {
          grade.at(i) = "C";
        } else {
          grade.at(i) = "D";
        }
      } else {
        grade.at(i) = "F";
      }
    }
  }

  for (int64_t i = 0; i < count; i++) {
    std::cout << grade.at(i) << std::endl;
  }

  return 0;
}
