#include <stdio.h>

int partial_sum(int *, int);

int main(int argc, char **argv) {
  int result;
  int i;
  int a[5];

  for (i=0; i<5; i++) {
    a[i] = i + 10;   
  }

  result = partial_sum(a, 3);
  printf("result = %d\n",result);
}

int partial_sum(int *array, int num) {
  int j;
  int sum=0;

  for (j=0; j<num; j++) 
    sum += array[j]; 
  return sum;
}
