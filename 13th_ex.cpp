/*В начале года были 4 группы по 35 человек, но после неуспешно 
сданной сессии, в каждой группе осталось разное количество людей. 
Необходимо оптимизировать, переведя групп из одной в другую, чтоб 
их стало примерно одинаковое количество. 
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void optimization(vector<int> &);

int main() {
  vector<int> groups = {30, 28, 29, 35};

  for (int it : groups) {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}

void optimization(vector<int> &groups) {
  while (*max_element(groups.begin(), groups.end()) -
        *min_element(groups.begin(), groups.end()) > 1) {
    auto minIt = min_element(groups.begin(), groups.end());
    auto maxIt = max_element(groups.begin(), groups.end());
    (*minIt)++;
    (*maxIt)--;
  }
}