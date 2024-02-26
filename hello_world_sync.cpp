#include <stdio.h>
#include <omp.h>

int some_calc(int array[], int num_threads) {

  int result = 0;
  
  for (int i=0; i<num_threads; i++) {      
    result += array[i];    
  }
  
  return  result;
  
}

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
  //  int my_calculated_variables[num_threads];
  int my_calculated_variable;  
  int iterations = 1000;


#pragma omp parallel
{  
  int ID = omp_get_thread_num();
  
  //  array[ID] = ID*ID;

  //#pragma omp barrier

  for (int i=ID; i<iterations; i+=num_threads) {

    my_calculated_variable = i*i;
    result += some_calc(my_calculated_variable);
    
  }
  
  //  my_calculated_variables[ID] = some_calc(array, num_threads) + ID;

}

 printf("%d \n", my_calculated_variable);
   

 return 0;
  
}
