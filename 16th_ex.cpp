/* Паша решил скрыть от родителей, что получил плохие
оценки по математике. Для этого он заменил двойки на
четверки и тройки на пятерки.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void replacing_grades(vector<int> &);

int main() {
  vector<int> grades = {2, 3, 4, 2, 5, 3, 2, 4, 3};
  replacing_grades(grades);
  for (int grade : grades) {
    cout << grade << " ";
  }
  cout << endl;

  return 0;
}

void replacing_grades(vector<int> &grades) {
  transform(grades.begin(), grades.end(), grades.begin(), [](int grade) {
    if (grade == 2) {
      return 4;
    } else if (grade == 3) {
      return 5;
    } else {
      return grade;
    }
  });
}