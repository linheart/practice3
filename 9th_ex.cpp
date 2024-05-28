/* Костя начинает изучать математику и хочет узнать, что такое операнды.
 Необходимо из матиматического выражения вывести все операнды.
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void find_operands(string &);

int main() {
  string expression = "12 + 34.5 - 6 * 78 / 9.01";

  find_operands(expression);

  cout << expression << endl;

  return 0;
}

void find_operands(string &expression) {
  expression.erase(
      remove_if(expression.begin(), expression.end(),
                [](char c) { return !isdigit(c) && c != '.' && c != ' '; }),
      expression.end());
}
