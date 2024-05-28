/*Есть список студентов, некоторые из которых решили уйти в
академический отпуск после сессии. Необходимо удалить этих
студентов из списка и вывести обновленный список.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void remove_students(vector<string> &, vector<string> &);

int main() {
  vector<string> students = {"Anna", "Ivan", "Maria", "Petr", "Katya"};
  vector<string> students_on_leave = {"Ivan", "Petr"};

  remove_students(students, students_on_leave);

  for (auto student : students) {
    cout << student << endl;
  }

  return 0;
}

void remove_students(vector<string> &students,
                     vector<string> &students_on_leave) {
  students.erase(remove_if(students.begin(), students.end(),
                           [students_on_leave](string student) {
                             return find(students_on_leave.begin(),
                                         students_on_leave.end(),
                                         student) != students_on_leave.end();
                           }),
                 students.end());
}
