#include <stdio.h>

#define SIZE 50
// Note add additional newline at end

int main() {
  int count = 0;
  int countAll = 0;
  char arr[10][SIZE];

  int index = 0;
  int last = 1;
  char *a;
  while ((a = fgets(arr[index++], SIZE + 2, stdin)) || last) {
    if (arr[index - 1][0] == '\n') {
      // process
      int people[SIZE][26] = {0};

      for (int i = 0; i < index; i++) {
        for (int j = 0; j < SIZE; j++) {
          if (arr[i][j] == '\n') {
            break;
          }

          people[i][arr[i][j] - 97] = 1;
        }
      }

      // for(int i = 0; i < 5; i++) {
      //   for(int j = 0; j < 5; j++) {
      //     printf("%d ", people[j][i]);
      //   }
      //   printf("\n");
      // }

      for (int j = 0; j < 26; j++) {
        for (int i = 0; i < SIZE; i++) {
          if (people[i][j]) {
            count++;
            break;
          }
        }
      }

      for (int j = 0; j < 26; j++) {
        int tmpCount = 0;

        for (int i = 0; i < SIZE; i++) {
          if (people[i][j]) {
            tmpCount++;
          }
        }

        if (tmpCount == index - 1) {
          countAll++;
        }
      }

      index = 0;
      continue;
    }

    if (!a && last) {
      break;
    }
  }

  printf("First: %d\n", count);
  printf("Second: %d\n", countAll);

  return 0;
}
