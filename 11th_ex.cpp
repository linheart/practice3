/* Комиссия решила проверить среднюю успеваемость студентов. Для
этого они решили посмотреть k самых часто встречаемых оценок.
Необходимо вывести k оценок, которые встречаются чаще всего.
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> top_k_frequent(vector<int> &, int);

int main() {
  vector<int> nums = {3, 4, 4, 2, 5, 3, 2, 4, 3, 3, 4, 2};
  int k = 2;

  vector<int> result = top_k_frequent(nums, k);

  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

vector<int> top_k_frequent(vector<int> &nums, int k) {
  map<int, int> freq;

  for (int num : nums) {
    freq[num]++;
  }

  vector<int> result;

  for (int i = 0; i < k; i++) {
    auto max_el = max_element(freq.begin(), freq.end(), [](auto a, auto b) {
      return a.second < b.second;
    });
    result.push_back(max_el->first);
    freq.erase(max_el);
  }

  return result;
}