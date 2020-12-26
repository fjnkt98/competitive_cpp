#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<Bint> A(N);
  Bint threshold = 1000000000000000000;
  
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  sort(A.begin(), A.end());

  Bint product = 1;
  for (int i = 0; i < N; i++) {
    product *= A.at(i);
    //if (product.str().length() > 19) {
    // cout << product.str().length() << endl;
    //  return 0;
    //}
    if (product > threshold) {
      cout << -1 << endl;
      return 0;
    }
  }
  
  cout << product << endl;
}