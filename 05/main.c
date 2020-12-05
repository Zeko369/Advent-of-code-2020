#include <stdio.h>

int row(char *arr) {
  int low = 0;
  int high = 127;

  for(int i = 0; i < 7; i++) {
    if(i == 6) {
      if(arr[i] == 'F') {
        return low;
      }

      return high;
    }

    if(arr[i] == 'F') {
      high = high - (high - low) / 2 - 1;
    } else if (arr[i] == 'B') {
      low = low + (high - low) / 2 + 1;
    }
  }
}

int column(char *arr) {
  int low = 0;
  int high = 7;

  for(int i = 7; i < 10; i++) {
    if(i == 9) {
      if(arr[i] == 'L') {
        return low;
      }

      return high;
    }

    if(arr[i] == 'L') {
      high = high - (high - low) / 2 - 1;
    } else if (arr[i] == 'R') {
      low = low + (high - low) / 2 + 1;
    }
  }
}

int getSeatId(char *arr) {
  int r = row(arr);
  int c = column(arr);

  return r * 8 + c;
}

int main() {
  char arr[11];
  int largest = -1;
  int ids[1024] = {0};

  int count = 0;

  while(fgets(arr, 12, stdin)) {
    int tmp = getSeatId(arr);

    ids[tmp] = 1;
    count++;

    if(tmp > largest) {
      largest = tmp;
    }
  }

  printf("First: %d\n", largest);

  for(int i = 0; i < 127; i++) {
    for(int j = 0; j < 7; j++) {
      int index = i * 8 + j;

      if(ids[index - 1] == 1 && ids[index + 1] == 1 && ids[index] == 0) {
        printf("Second: %d\n", index);
      }

      // if(ids[index]) {
      //   printf("Seat %d\n", index);
      // } else {
      //   printf("Not  %d\n", index);
      // }
    }
  }

  return 0;
}
