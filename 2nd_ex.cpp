/* Создается массив случайных чисел. На вход подается число n.
Необходимо отсортировать массив таким образом, чтобы каждые
n элементов были в порядке возрастания, а следующие n элементов
были в порядке убывания, и так до конца массива.
*/

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#define arr_size 10

using namespace std;

int gen_rand_num();
void init(vector<int> &);
void sort_arr(vector<int> &, int);

int main() {
  int n;
  cin >> n;

  vector<int> arr(arr_size);
  init(arr);

  for (auto it : arr) {
    cout << it << ' ';
  }

  sort_arr(arr, n);
  cout << endl;
  for (auto it : arr) {
    cout << it << ' ';
  }

  return 0;
}

int gen_rand_num() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(0, 100);
  return dis(gen);
}

void init(vector<int> &arr) {
  for (int i = 0; i < arr_size; i++) {
    arr[i] = gen_rand_num();
  }
}

void sort_arr(vector<int> &arr, int n) {
  int size = arr.size();

  for (int i = 0; i < size; i += n) {
    sort(arr.begin() + i, min(arr.begin() + i + n, arr.end()));
  }

  for (int i = n; i < size; i += 2 * n) {
    sort(arr.begin() + i, min(arr.begin() + i + n, arr.end()), greater<int>());
  }
}