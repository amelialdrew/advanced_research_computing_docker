#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
 
int main() {
  
  int i;
  int x = 44;
  
#pragma omp parallel for private(x)
  for(i=0;i<=10;i++) {
    x=i;
    printf("Thread number: %d     x: %d\n",omp_get_thread_num(),x);
  }
  
  printf("x is %d\n", x);
 
}
