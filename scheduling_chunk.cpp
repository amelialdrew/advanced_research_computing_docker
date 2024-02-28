//Adapted from https://www.inf.ufsc.br/~bosco.sobral/ensino/ine5645/OpenMP_Dynamic_Scheduling.pdf
#include <unistd.h>
#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#define THREADS 16
#define N 100000000
#define CHUNK 100

int main ( ) {
  int i;

  printf("Running %d iterations on %d threads dynamically.\n", N, THREADS);
  
  //#pragma omp parallel for schedule(dynamic, CHUNK) num_threads(THREADS)
#pragma omp parallel for schedule(guided) num_threads(THREADS)  
  for (i = 0; i < N; i++) {
    int j = i*i;
  }
  
  /* all threads done */
  printf("All done!\n");
  return 0;
}
