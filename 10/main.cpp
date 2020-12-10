#include <algorithm>
#include <iostream>

#define MAX_SIZE 1000

int first(const int* arr, int n) {
  int diffs[3] = {0};
  for (int i = 0; i < n; i++) {
    int diff = arr[i + 1] - arr[i];
    diffs[diff - 1]++;
  }

  return diffs[0] * diffs[2];
}

int rec(const int* arr, int n, int from) {
  if (from == n) {
    return 1;
  }

  int tmp = 0;
  for (int i = 1; i < 3; i++) {
    if (i + from <= n && arr[i + from] - arr[from] <= 3) {
      tmp += rec(arr, n, from + i);
    }
  }

  return tmp;
}

int second(const int* arr, int n) { return rec(arr, n, -1); }

int main() {
  int arr[MAX_SIZE];
  int tmp = 0;

  int n = 1;
  arr[0] = 0;
  while (std::cin >> tmp) {
    arr[n++] = tmp;
  }

  std::sort(arr, arr + n);
  arr[n] = arr[n - 1] + 3;

  std::cout << "First: " << first(arr, n) << std::endl;
  std::cout << "Second: " << second(arr, n) << std::endl;

  return 0;
}
