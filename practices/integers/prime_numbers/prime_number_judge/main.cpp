#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// 素数判定を行う．
bool is_prime(uint64_t N) {
  // 1は素数ではない
  if (N == 1)
    return false;

  // √Nまで探索を行えばよい．
  // i * i < Nと書くと√Nまで簡単に探索できる
  for (uint64_t i = 2; i * i <= N; i++) {
    // 割り切れる数が見つかれば素数ではない．
    if (N % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  uint64_t N;
  cin >> N;
  if (is_prime(N)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

}