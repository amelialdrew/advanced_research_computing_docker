//Adapted from https://www.inf.ufsc.br/~bosco.sobral/ensino/ine5645/OpenMP_Dynamic_Scheduling.pdf
#include <unistd.h>
#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#define THREADS 4
#define N 16

int main ( ) {
  int i;
  
#pragma omp parallel for schedule(dynamic) num_threads(THREADS)
  for (i = 0; i < N; i++) {
    sleep(i);
    printf("Thread %d is doing iteration %d.\n", omp_get_thread_num(), i);
  }
  
  /* all threads done */
  printf("All done!\n");
  return 0;
}
