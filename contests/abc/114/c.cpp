#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>

void dfs(std::set<std::string>& result, std::string S) {
  if (!S.empty() && std::stoll(S) > 1e9) return;

  result.insert(S);

  dfs(result, S + "3");
  dfs(result, S + "5");
  dfs(result, S + "7");
}

int main() {
  int64_t N;
  std::cin >> N;

  std::set<std::string> result;
  std::string S = "";
  dfs(result, S);

  int64_t answer = 0;
  for (auto r : result) {
    if (r.empty()) continue;

    std::unordered_map<char, int64_t> count;
    for (auto c : r) {
      count[c] += 1;
    }

    if (count['3'] == 0 || count['5'] == 0 || count['7'] == 0) continue;

    if (std::stoll(r) <= N) answer++;
  }

  std::cout << answer << std::endl;

  return 0;
}