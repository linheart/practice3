/* Есть группа учеников, каждый из которых пришел сдавать лабораторную
работу. Каждая лабораторная работа имеет сложность, которая обозначается
числом от 1 до 5.
Нужно составить такую очередь, чтобы преподаватель смог принять максимальное
количество лабораторных работ за определенное время.
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using Students = vector<pair<string, pair<string, int>>>;

int main() {
  Students students = {{"Alexei", {"lab7", 1}}, {"Ivan", {"lab6", 5}},
                       {"Ilya", {"lab3", 4}},   {"Semen", {"lab4", 3}},
                       {"Katya", {"lab2", 4}},  {"Sasha", {"lab5", 3}}};

  sort(students.begin(), students.end(),
       [](auto &a, auto &b) { return a.second.second < b.second.second; });

  for (auto &student : students) {
    cout << student.first << ": " << student.second.first << "("
         << student.second.second << ")" << endl;
  }

  return 0;
}
