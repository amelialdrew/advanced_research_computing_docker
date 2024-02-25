#include <stdio.h>
#include <omp.h>

int num_steps = 100000;
#define NUM_THREADS 4
double step;

int main ()
{
  int i;

  double pi = 0.;
  double sum[num_steps] = {0.}; //We need to know the number of threads before runtime, so we can set the size of the array  
  step = 1.0 / num_steps;

  omp_set_num_threads(NUM_THREADS);
  int global_num_threads = omp_get_num_threads();  

#pragma omp parallel for
  for (i=0; i<num_steps; i++)
    {
      double x;      
      x = (i+0.5)*step;
      sum[i] += 4.0/(1.0+x*x);
    }
  
 for(i=0, pi=0.0; i<num_steps; i++)
   {
     pi += step * sum[i];
   }

 printf("Answer: %f\n", pi);

}
