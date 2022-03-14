#include <stdio.h>
#include <stdlib.h>

int solve();
int isSolved();
void readFile(char* fileName);
#define MAX_DEPTH 100000

char puzzle[9][9];
int currentDepth = 0;

int main(int argc, char const *argv[]) {
  readFile("puzzle.txt"); // reads puzzle.txt into puzzle variable
  int solved = solve();
  // use recursion to solve
  return 0;
}

int solve() {
  currentDepth += 1;

  if (currentDepth == MAX_DEPTH) {
    puts("Max depth reached, breaking loop"); // breaks recursion loop if too deep
    return 0;
  }

  int solved = isSolved();

  if (solved == 1) {
    return 1;
  }

  char foundNums[9];
  int availableNums = 9;

  solve();
}

int isSolved() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (puzzle[i][j] == '0') {
        return 0;
      }
    }
  }

  return 1;
}

void readFile(char* fileName) {
      FILE *fp;
      char num;

      fp = fopen(fileName, "r");

      if (fp == NULL) {
          printf("file '%s' did not open \n", fileName);
      }
      else {
          int i = 0;
          int j = 0;

          while ((num = fgetc(fp)) != EOF) {
              if (num != '\n' && num != ' ') {
                puzzle[i][j] = num;
                j += 1;
              }

              if (j == 9) {
                i += 1;
                j = 0;
              }
          }

          for (int k = 0; k < 9; k++) {
            for (int l = 0; l < 9; l++) {
              printf("%c ", puzzle[k][l]);
            }
             puts(" ");
          }
      }

      //5
      fclose(fp);
}
