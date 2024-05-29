/* У Васи есть баллы по физике. Необходимо вычислить
сумму баллов, чтобы удостовериться, есть ли шанс получить автомат.
*/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int calculateTotalScore(const vector<int> &scores) {
  return accumulate(scores.begin(), scores.end(), 0);
}

int main() {
  vector<int> scores = {10, 15, 7, 9, 13, 14, 8};

  int totalScore = calculateTotalScore(scores);

  cout << "Сумма баллов Васи: " << totalScore << endl;

  return 0;
}
