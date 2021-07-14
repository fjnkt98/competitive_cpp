#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
  std::string word;
  std::cin >> word;

  std::vector<std::string> sentence;
  while (true) {
    std::string w;
    std::cin >> w;

    if (w == "END_OF_TEXT") {
      break;
    } else {
      sentence.push_back(w);
    }
  }

  int64_t count = 0;
  for (auto w : sentence) {
    std::string lowerd_w;

    for (size_t i = 0; i < w.size(); i++) {
      lowerd_w.push_back(std::tolower(w.at(i)));
    }

    if (lowerd_w == word) {
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
