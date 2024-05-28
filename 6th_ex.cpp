/* Студенты, проживающие в 10м общежитие не должны иметь больше
одной тройки за семестр. Необходимо проверить, есть ли студенты,
не удовлетворяющие условию и переселить их в 6е общежитие.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  vector<int> grades;
};

void relocate_students(vector<Student> &);

int main() {
  vector<Student> students = {{"Ivan", {5, 3, 3, 4}},
                              {"Sasha", {5, 3, 4, 4}},
                              {"Semen", {4, 5, 4, 5}},
                              {"Petr", {4, 4, 3, 3}},
                              {"Egor", {5, 5, 5, 5}}};

  relocate_students(students);

  for (auto student : students) {
    cout << student.name << endl;
  }

  return 0;
}

void relocate_students(vector<Student> &students) {
  students.erase(remove_if(students.begin(), students.end(),
                           [](Student student) {
                             return count(student.grades.begin(),
                                          student.grades.end(), 3) > 1;
                           }),
                 students.end());
}