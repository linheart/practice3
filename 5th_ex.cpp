/*Есть группа студентов и их суммарные оценки за семестр
 по стобалльной системе. Необходимо преобразовать оценки
 в пятибальную систему.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  int score;
};

void transform_scores(vector<Student> &);

int main() {
  vector<Student> students = {
      {"Ivan", 90}, {"Maria", 75}, {"Vasya", 63}, {"Semen", 44}};

  transform_scores(students);

  for (auto student : students) {
    cout << student.name << ": " << student.score << endl;
  }

  return 0;
}

void transform_scores(vector<Student> &students) {
  for (auto it = students.begin(); it != students.end(); ++it) {
    if (it->score >= 84) {
      it->score = 5;
    } else if (it->score >= 73) {
      it->score = 4;
    } else if (it->score >= 50) {
      it->score = 3;
    } else {
      it->score = 0;
    }
  }
}