/*Коля и Саша в течение года записывали свой доход за
месяц. Необходимо определить медианный доход Коли и Саши.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

double find_median(vector<int> &);
double joint_median_income(vector<int> &, vector<int> &);

int main() {
  vector<int> kolias_incomes = {33000, 30000, 37000, 32000, 35000};
  vector<int> sashas_incomes = {41000, 32000, 44000, 40000, 30000};

  double medianIncome = joint_median_income(kolias_incomes, sashas_incomes);

  cout << medianIncome << endl;

  return 0;
}

double find_median(vector<int> &incomes) {
  sort(incomes.begin(), incomes.end());
  int n = incomes.size();
  if (n % 2 == 0) {
    return (incomes[n / 2 - 1] + incomes[n / 2]) / 2.0;
  } else {
    return incomes[n / 2];
  }
}

double joint_median_income(vector<int> &kolias_incomes,
                           vector<int> &sashas_incomes) {
  vector<int> joint_incomes;
  joint_incomes.insert(joint_incomes.end(), kolias_incomes.begin(),
                       kolias_incomes.end());
  joint_incomes.insert(joint_incomes.end(), sashas_incomes.begin(),
                       sashas_incomes.end());

  return find_median(joint_incomes);
}
