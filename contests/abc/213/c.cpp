#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

class Data {
  public:
    int64_t index;
    int64_t row;
    int64_t column;

    Data(int64_t index = 0, int64_t row = 0, int64_t column = 0)
      :index(index),
      row(row),
      column(column)
    {
    }
};

bool compare_index(const Data& a, const Data& b) {
  return (a.index < b.index);
}

bool compare_row(const Data& a, const Data& b) {
  return (a.row < b.row);
}

bool compare_column(const Data& a, const Data& b) {
  return (a.column < b.column);
}

int main() {
  int64_t H, W, N;
  std::cin >> H >> W >> N;
  std::vector<Data> array(N);
  std::map<int64_t, int64_t> row;
  std::map<int64_t, int64_t> column;
  for (int64_t i = 0; i < N; i++) {
    int64_t A, B;
    std::cin >> A >> B;
    array.at(i).index = i;
    array.at(i).row = A;
    array.at(i).column = B;
    row[A]++;
    column[B]++;
  }

  std::sort(array.begin(), array.end(), compare_row);
  int64_t void_row_count = 0;
  int64_t previous_row = 0;
  for (int64_t i = 0; i < N; i++) {
    if (array.at(i).row != previous_row) {
      void_row_count += array.at(i).row - previous_row - 1;
    }

    previous_row = array.at(i).row;
    array.at(i).row -= void_row_count;
  }

  std::sort(array.begin(), array.end(), compare_column);
  int64_t void_column_count = 0;
  int64_t previous_column = 0;
  for (int64_t i = 0; i < N; i++) {
    if (array.at(i).column != previous_column) {
      void_column_count += array.at(i).column - previous_column - 1;
    }

    previous_column = array.at(i).column;
    array.at(i).column -= void_column_count;
  }

  std::sort(array.begin(), array.end(), compare_index);
  for (int64_t i = 0; i < N; i++) {
    std::cout << array.at(i).row << " " << array.at(i).column << std::endl;
  }

  return 0;
}
