#include <algorithm>
#include <iostream>

#define MAX_SIZE 1000

int first(const int* arr, int n) {
  int diffs[3] = {0};
  for (int i = 0; i < n; i++) {
    int diff = arr[i + 1] - arr[i];

    if (diff > 3) {
      return -1;
    }

    diffs[diff - 1]++;
  }

  return diffs[0] * diffs[2];
}

int second(const int* arr, int n, int from = 1, int t = 0) {
  if (from >= n - 1) {
    return 1;
  }

  // 1 4 5 6 7
  // 1 4 5 7
  // 1 4 6 7
  // 1 4 7

  int tmp = t;

  for (int i = 1; i < 4; i++) {
    if (arr[from + i] - arr[from] <= 3 && arr[from + i] > 0) {
      std::cout << from << "|" << i << " " << arr[from] << "=>" << arr[from + i]
                << std::endl;
      int val = second(arr, n, from + i, t);
      std::cout << "Count: " << val << std::endl;
      tmp += val;
    }
  }

  return tmp;
}

int second_v2(const int* arr, int n) {
  std::cout << std::endl;

  int tmp[n][3];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      tmp[i][j] = 0;
    }
  }

  for (int i = 1; i < n - 1; i++) {
    for (int j = 0; j < ((n <= 3 + i) ? n - i : 3); j++) {
      if (arr[i + j + 1] - arr[i] <= 3) {
        tmp[i - 1][j]++;
      }
    }
  }

  for (int i = 1; i < n; i++) {
    std::cout << arr[i];
    std::cout << " ";
  }

  std::cout << std::endl;
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < n - 1; i++) {
      std::cout << tmp[i][j] << " ";
      if (arr[i + 1] >= 10) {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }

  int out = 1;
  for (int i = 0; i < n - 1; i++) {
    int count = tmp[i][0] + tmp[i][1] + tmp[i][2];

    if (count > 1) {
      out += count;
    }
  }

  return out * out;
}

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

  for (int i = 0; i < n + 1; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "First: " << first(arr, n) << std::endl;
  std::cout << "Second: " << second_v2(arr, n) << std::endl;

  return 0;
}
