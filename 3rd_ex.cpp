/* У Васи был набор целых чисел. Коля решил пошутить над Васей
и добавил в набор буквы. Необходимо найти буквы в наборе и удалить их.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void remove_letters(vector<string>&);

int main() {
  vector<string> arr = {"123a32", "132143", "d1123"};

  remove_letters(arr);

  for (auto it : arr) {
    cout << it << ' ';
  }
  cout << endl;

  return 0;
}

void remove_letters(vector<string> &arr) {
  transform(arr.begin(), arr.end(), arr.begin(), [](string str) {
    str.erase(
        remove_if(str.begin(), str.end(), [](char c) { return isalpha(c); }),
        str.end());
    return str;
  });
}