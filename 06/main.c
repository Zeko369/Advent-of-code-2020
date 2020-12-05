#include <stdio.h>

int main() {
  char arr[5];

  while(fgets(arr, 4 + 2, stdin)) {
    arr[4] = '\0';
    printf("%s\n", arr);
  }

  return 0;
}
