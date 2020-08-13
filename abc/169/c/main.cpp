#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

using namespace std;

int main() {
  uint64_t A;
  string Bs;
  istringstream Bss;
  int B = 0;
  cin >> A >> Bs;

  Bs.erase(1, 1);
  Bss = istringstream(Bs);
  Bss >> B;
  
  uint64_t product = A * B / 100;

  cout << product << endl;
}