/* Из 3х групп есть по 4 студента с несдавшими работами.
Преподаватель может проверять лабораторные работы только
у одного человека с группы по расписанию. Чтобы студентам
не снизили баллы за просроченное время, преподаватель
решил проверять сначала у тех, у кого больше несданных работ.
Необходимо найти людей, у которых будут проверятьсяя работы.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> select_students(vector<int>);

int main() {
  vector<int> students = {3, 2, 4, 5, 4, 3, 3, 2, 2, 3, 2, 4};
  vector<int> selected_students = select_students(students);

  for (auto it : selected_students) {
    cout << it << ' ';
  }
  cout << endl;
  return 0;
}

vector<int> select_students(vector<int> students) {
  vector<int> selected_students;
  for (int i = 0; i < 3; i++) {
    auto student =
        max_element(students.begin() + i * 4, students.begin() + i * 4 + 4);
    selected_students.push_back(*student);
  }
  return selected_students;
}