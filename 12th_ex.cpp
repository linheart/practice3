/* Петя нашел калькулятор чисел, но результаты выдаются в двоичном
представлении. Необходимо перевести результат в десятичное число.
*/

#include <iostream>
#include <numeric>

using namespace std;

int main() {
  string binary = "110";

  int decimal =
      accumulate(binary.begin(), binary.end(), 0,
                 [](int acc, char bit) { return (acc << 1) + (bit - '0'); });

  cout << binary << " - " << decimal << endl;

  return 0;
}
