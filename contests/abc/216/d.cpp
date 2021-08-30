#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
  // Receive inputs
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> A(M);
  std::vector<std::vector<int64_t>> bucket(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t k;
    std::cin >> k;
    for (int64_t j = 0; j < k; j++) {
      int64_t a;
      std::cin >> a;
      A.at(i).push_back(a - 1);
    }

    std::reverse(A.at(i).begin(), A.at(i).end());
    bucket.at(A.at(i).back()).push_back(i);
  }

  // Find the index of the cylinder that has the ball of the same color among the
  // currently visible balls, and store them in the queue.
  std::queue<int64_t> completed_color;
  for (int64_t i = 0; i < N; i++) {
    if (bucket.at(i).size() == 2) {
      completed_color.push(i);
    }
  }

  // Repeat until the queue is empty
  while (!completed_color.empty()) {
    // Pick out the color to be processed this loop from the queue
    int64_t target_color = completed_color.front();
    // Pop the color from front of queue
    completed_color.pop();

    // Remove the ball from the cylinders which has the ball of the color
    for (auto index : bucket.at(target_color)) {
      A.at(index).pop_back();
      if (!A.at(index).empty()) {
        // Put the second ball from the top in the bucket
        bucket.at(A.at(index).back()).push_back(index);
        // When the colors are complete, put them in the queue
        if (bucket.at(A.at(index).back()).size() == 2) {
          completed_color.push(A.at(index).back());
        }
      }
    }
  }

  bool ok = true;
  for (int64_t i = 0; i < M; i++) {
    if (!A.at(i).empty()) {
      ok = false;
    }
  }

  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
