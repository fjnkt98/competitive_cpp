#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int X, N;
  cin >> X >> N;

  if (N == 0) {
    cout << X << endl;
  } else {
    vector<int> p(N);

    for (int i = 0; i < N; i++) {
      cin >> p.at(i);
    }

    // 出力しうる数字のリスト
    vector<int> nature(201);
    // 初期化
    for (int i = 0; i < 201; i++) {
      nature.at(i) = i;
    }

    // pを降順ソートしておく
    sort(p.begin(), p.end(), greater<int>());

    // 禁止リストの要素を排除
    for (auto pi : p) {
      nature.erase(nature.begin() + pi);
    }

    // 出力可能性リストを降順ソート
    sort(nature.begin(), nature.end(), greater<int>());

    int minimum_diff = 1000;
    int answer = 0;

    for (auto n : nature) {
      if (abs(X - n) <= minimum_diff) {
        minimum_diff = abs(X - n);
        answer = n;
      }
    }

    cout << answer << endl;
  }
}