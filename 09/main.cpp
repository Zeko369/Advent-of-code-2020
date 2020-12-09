#include <iostream>
#define MAX_SIZE 1000

// DEV
// #define COUNT 5

#define COUNT 25

bool can_sum(const int *arr, int from) {
  for (int i = from - COUNT; i < from - 1; i++) {
    for (int j = i + 1; j < from; j++) {
      // std::cout << arr[i] << " " << arr[j] << std::endl;

      if (arr[from] == arr[i] + arr[j]) {
        return true;
      }
    }
  }

  return false;
}

int first(const int *arr, int n) {
  for (int i = COUNT; i < n - 1; i++) {
    bool ok = can_sum(arr, i);
    if (!ok) {
      return arr[i];
    }
  }
}

int main() {
  int arr[MAX_SIZE] = {0};
  int tmp = 0;

  int index = 0;
  while (std::cin >> tmp) {
    arr[index++] = tmp;
  }

  int first_result = first(arr, index);
  int second_result = second(arr, index, first_result);

  std::cout << "First: " << first_result << std::endl;
  std::cout << "Second: " << first_result << std::endl;

  return 0;
}
