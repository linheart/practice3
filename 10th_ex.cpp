/*Паша и Валя загаздывают слова. Необходимо определить,
являются ли полученные слова анаграммами друг друга.
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool are_anagrams(string, string);

int main() {
  string word1 = "listen";
  string word2 = "silent";

  cout << are_anagrams(word1, word2) << endl;
  return 0;
}

bool are_anagrams(string word1, string word2) {
  if (word1.length() != word2.length()) {
    return false;
  }

  sort(word1.begin(), word1.end());
  sort(word2.begin(), word2.end());

  return word1 == word2;
}
