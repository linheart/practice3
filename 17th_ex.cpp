#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int trap(vector<int> &);

int main() {
  vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << trap(heights) << endl;
  return 0;
}

int trap(vector<int> &height) {
  int n = height.size();
  vector<int> left_max(n), right_max(n);

  partial_sum(height.begin(), height.end(), left_max.begin(),
              [](int a, int b) { return max(a, b); });

  partial_sum(height.rbegin(), height.rend(), right_max.rbegin(),
              [](int a, int b) { return max(a, b); });

  int water = 0;
  for (auto it = height.begin(); it != height.end(); it++) {
    int i = distance(height.begin(), it);
    water += min(left_max[i], right_max[i]) - height[i];
  }

  return water;
}
