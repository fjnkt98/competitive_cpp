#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::pair<int64_t, int64_t>> students(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    int64_t class_number, exam_point;
    std::cin >> class_number >> exam_point;
    students.at(i) = std::make_pair(class_number, exam_point);
  }

  int64_t Q;
  std::cin >> Q;
  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t left, right;
    std::cin >> left >> right;
    query.at(i) = std::make_pair(left, right);
  }

  std::vector<int64_t> class1_cumsum(N + 1, 0);
  std::vector<int64_t> class2_cumsum(N + 1, 0);
  for (int64_t i = 1; i <= N; i++) {
    if (students.at(i).first == 1) {
      class1_cumsum.at(i) = students.at(i).second + class1_cumsum.at(i - 1);
      class2_cumsum.at(i) = class2_cumsum.at(i - 1);
    } else {
      class1_cumsum.at(i) = class1_cumsum.at(i - 1);
      class2_cumsum.at(i) = students.at(i).second + class2_cumsum.at(i - 1);
    }
  }

  for (int64_t i = 0; i < Q; i++) {
    int64_t class1_answer = class1_cumsum.at(query.at(i).second) - class1_cumsum.at(query.at(i).first - 1);
    int64_t class2_answer = class2_cumsum.at(query.at(i).second) - class2_cumsum.at(query.at(i).first - 1);
    std::cout << class1_answer << " " << class2_answer << std::endl;
  }

  return 0;
}
