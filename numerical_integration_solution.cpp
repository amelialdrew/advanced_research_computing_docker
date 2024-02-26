#include <stdio.h>
#include <omp.h>

int num_steps = 100000;
#define NUM_THREADS 4
double step;

int main ()
{
  int i;
  int global_num_threads;

  double pi = 0.;
  double sum[NUM_THREADS] = {0.}; //We need to know the number of threads before runtime, so we can set the size of the array  
  step = 1.0 / num_steps;

  omp_set_num_threads(NUM_THREADS);

#pragma omp parallel
{
  int num_threads = omp_get_num_threads();
  int thread_id = omp_get_thread_num();

  //  printf("Threads: %d, %d\n", num_threads, thread_id); 

  double x;
  int i;

  if (thread_id == 0)
    global_num_threads = num_threads; //This should only be copied by one thread                                             

  for (i=thread_id, sum[thread_id]=0.0; i<num_steps; i=i+num_threads)
    {
      x = (i+0.5)*step;
      sum[thread_id] += 4.0/(1.0+x*x);
    }

}
 
 for(i=0, pi=0.0; i<global_num_threads; i++)
   {
     pi += step * sum[i];
   }

 printf("Answer: %f\n", pi);

}
