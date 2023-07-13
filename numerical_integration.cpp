#include <stdio.h>

int num_steps = 100000;
double step;

int main ()
{

  int i;
  double x, pi;
  double sum = 0.0;
  step = 1.0 / num_steps;
  
  for (i=0; i<num_steps; i++)
    {
      x = (i+0.5)*step;
      sum = sum + 4.0/(1.0+x*x);
    }
  
  pi = step * sum;
  printf("Answer: %f\n", pi);
  
}
