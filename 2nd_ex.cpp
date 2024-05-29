/*Семен сделал 7 лабораторных работ по программированию.
Он решил узнать, насколько классный его код. Для этого
Семен решил использовать индекс Хирша. Необходимо вычислить
индекс Хирша Семена.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int calculate_h_index(vector<int> &);

int main() {
  vector<int> citations = {3, 7, 9, 6, 5, 10, 6};

  int h_index = calculate_h_index(citations);

  cout << h_index << endl;

  return 0;
}

int calculate_h_index(vector<int> &citations) {

  sort(citations.begin(), citations.end(), greater<int>());

  int h_index = 0;
  int position = 0;

  for_each(citations.begin(), citations.end(),
           [&h_index, &position](int citation) {
             position++;
             if (citation >= position) {
               h_index = position;
             }
           });

  return h_index;
}