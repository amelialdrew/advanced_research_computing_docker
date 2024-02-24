#include <stdio.h>
#include <omp.h>

int some_calc(int array[], int num_threads) {

  int result = 0;
  
  for (int i=0; i<num_threads; i++) {      
    result += array[i];    
  }
  
  return  result;
  
}



int main() {

  int num_threads = 4;
  omp_set_num_threads(num_threads);
  int array[num_threads];
  int result = 0;
  int my_calculated_variables[num_threads];    


#pragma omp parallel
{  
  int ID = omp_get_thread_num();
  
  array[ID] = ID*ID;

  //#pragma omp barrier
  
  my_calculated_variables[ID] = some_calc(array, num_threads) + ID;

}

 for (int i=0; i<num_threads; i++) {

   printf("%d \n", my_calculated_variables[i]);
   
 }

 return 0;
  
}
