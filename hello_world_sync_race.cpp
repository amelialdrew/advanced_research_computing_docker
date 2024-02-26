#include <stdio.h>
#include <omp.h>

int some_calc(int array) {

  int result_func = 0;
  result_func = array;      
  return  result_func;
  
}


int main() {

  int num_threads = 4;
  omp_set_num_threads(num_threads);
  int array[num_threads];
  int result = 0;
  int iterations = 1000;


#pragma omp parallel
{
  int my_calculated_variable;    
  int ID = omp_get_thread_num();
  
  for (int i=ID; i<iterations; i+=num_threads) {

    my_calculated_variable = i*i*i;

#pragma omp critical    
    result += some_calc(my_calculated_variable);
    
  }
  
}

 printf("%d \n", result);     

 return 0;
  
}
