#include <stdio.h>

int main()
{
    int sum = 0;

    //#pragma omp parallel for 
    for (int i=0; i<2000000000; i++)
    {
        if(i % 1000 ==0)
            sum += i;   
    }

    printf("%i\n", sum);

    return 0;

}
