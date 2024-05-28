/*Иван решил написать предложение, в котором есть
каждая буква алфавита. Необходимо определить,
является ли строка панаграмой.
*/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <set>
#include <string>

using namespace std;

bool is_pangram(string);

int main() {
  string sentence = "The quick brown fox jumps over the lazy dog";

  cout << is_pangram(sentence) << endl;

  return 0;
}

bool is_pangram(string sentence) {
  set<char> alphabet;

  for_each(sentence.begin(), sentence.end(), [&alphabet](char ch) {
    if (isalpha(ch)) {
      alphabet.insert(tolower(ch));
    }
  });

  return alphabet.size() == 26;
}