#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define SIZE 20000000

int A[SIZE][10];
int C[200];

static int subset(int bound) {
  return bound - 10;
}

int main(int argc, char **argv) {
  struct timeval start,end;
  double elapsed;
  int i,k;

  // Start timer
  gettimeofday(&start, NULL);

  // Code to optimize
  for (i=0; i < subset(SIZE); i++) {
    for (k=0; k < 200; k++) {
      C[k] += A[i][3];
    }
  }

  // End timer
  gettimeofday(&end, NULL);

  // Print out elapsed time
  elapsed = ((end.tv_sec*1000000.0 + end.tv_usec) -
            (start.tv_sec*1000000.0 + start.tv_usec)) / 1000000.00;
  printf("Elapsed time: %.3f\n",elapsed);

  exit(0);
}

