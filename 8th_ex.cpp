/* Вася написал огромный текст и решил узнать, какое
слово чаще всего используется в тексте. Необходимо вывести
самое часто встречающее слово и количество его повторений.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string text = "this is a test this test is only a test";

  istringstream iss(text);
  map<string, int> word_count;
  string word;

  while (iss >> word) {
    ++word_count[word];
  }

  auto most_frequent =
      max_element(word_count.begin(), word_count.end(),
                  [](const pair<string, int> &a, const pair<string, int> &b) {
                    return a.second < b.second;
                  });

  cout << most_frequent->first << ' ' << most_frequent->second << endl;
  return 0;
}
