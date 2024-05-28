/*Саша и Коля соревнуются, у кого больше баллов за решенные задачи.
Необходимо посчитать сумму всех баллов и сравнить результаты.
*/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int total_score(vector<int> &);
void find_winner(int, int);

int main() {
  vector<int> sasha_scores = {5, 10, 15, 20};
  vector<int> kolya_scores = {10, 10, 10, 10};

  int sasha_total = total_score(sasha_scores);
  int kolya_total = total_score(kolya_scores);

  find_winner(sasha_total, kolya_total);
  return 0;
}

void find_winner(int sasha_total, int kolya_total) {
  if (sasha_total > kolya_total) {
    cout << "Sasha win." << endl;
  } else if (kolya_total > sasha_total) {
    cout << "Kolya win." << endl;
  } else {
    cout << "The scores are the same" << endl;
  }
}

int total_score(vector<int> &scores) {
  return accumulate(scores.begin(), scores.end(), 0);
}