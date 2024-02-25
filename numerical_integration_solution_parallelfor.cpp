#include <stdio.h>
#include <omp.h>

int num_steps = 100000;
double step;

int main ()
{
  int i;

  double pi = 0.;
  double sum[num_steps] = {0.}; //We need to know the number of threads before runtime, so we can set the size of the array  
  step = 1.0 / num_steps;

#pragma omp parallel for num_threads(4)
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
