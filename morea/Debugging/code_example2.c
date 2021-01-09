#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MyStruct {
  int id;
  char *name;
  int num_values;
  double *values;
};

double partial_sum(struct MyStruct **, int);

int main(int argc, char **argv) {
  double result;
  int i;
  struct MyStruct *a[5];
 
  for (i=0; i<5; i++) {
    int j;
    char buffer[16];

    a[i] = (struct MyStruct *)calloc(1,sizeof(struct MyStruct));  
    a[i]->id = i;
    sprintf(buffer,"name-%d",a[i]->id);
    a[i]->name = strdup(buffer);
    a[i]->num_values = 3+i; 
    a[i]->values = (double *)calloc(a[i]->num_values,sizeof(double));
    for (j=0; j<a[i]->num_values; j++) 
      a[i]->values[j] = (double)(i+j+12.0);
  }

  result = partial_sum(a, 3);
  printf("result = %lf\n",result);
}

double partial_sum(struct MyStruct **array, int num) {
  int i,j;
  double sum=0;

  for (i=0; i<num; i++)  {
    for (j=0; j<array[i]->num_values; j++)
      sum += array[i]->values[j]; 
  }
  return sum;
}
