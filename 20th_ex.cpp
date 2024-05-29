/* Весь год Коля списывал контрольные у Васи. Вася
решил проверить, совпадают ли их оценки. Необходимо
сравнить все оценки Коли и Васи и вывести несовпадающие
оценки.
*/

#include <algorithm> // Для mismatch
#include <iostream>
#include <vector>

using namespace std;

void find_mismatched_grades(vector<int>, vector<int>);

int main() {
  vector<int> kolya_grades = {85, 88, 78, 92, 85};
  vector<int> vasya_grades = {85, 90, 78, 92, 88};

  find_mismatched_grades(vasya_grades, kolya_grades);

  return 0;
}

void find_mismatched_grades(vector<int> vasya_grades,
                            vector<int> kolya_grades) {
  auto mismatchPair = mismatch(vasya_grades.begin(), vasya_grades.end(),
                               kolya_grades.begin(), kolya_grades.end());

  while (mismatchPair.first != vasya_grades.end() &&
         mismatchPair.second != kolya_grades.end()) {
    cout << "Vasya: " << *mismatchPair.first
         << ", Kolya: " << *mismatchPair.second << endl;

    ++mismatchPair.first;
    ++mismatchPair.second;

    mismatchPair = mismatch(mismatchPair.first, vasya_grades.end(),
                            mismatchPair.second, kolya_grades.end());
  }
}