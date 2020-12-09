#include <iostream>
#define MAX_SIZE 1000

int main() {
  std::string arr[MAX_SIZE];
  std::string tmp = "";

  int index = 0;
  while (std::cin >> tmp) {
    arr[index++] = tmp;
  }

  std::cout << arr[0] << std::endl;

  return 0;
}
