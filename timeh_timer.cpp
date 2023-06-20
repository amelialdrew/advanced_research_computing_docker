#include <iostream>
#include <time.h>

// Function to be timed
void someFunction()
{
    // Simulating some work
    for (int i = 0; i < 1000000000; ++i)
    {
        // Do some computation
    }
}

// Another function to be timed
void anotherFunction()
{
    // Simulating some work
    for (int i = 0; i < 500000000; ++i)
    {
        // Do some computation
    }
}

// Yet another function to be timed
void yetAnotherFunction()
{
    // Simulating some work
    for (int i = 0; i < 200000000; ++i)
    {
        // Do some computation
    }
}

int main()
{
    clock_t start, end;
    double duration;

    // Time someFunction()
    start = clock();
    someFunction();
    end = clock();
    duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    std::cout << "Elapsed time for someFunction(): " << duration << " seconds" << std::endl;

    // Time anotherFunction()
    start = clock();
    anotherFunction();
    end = clock();
    duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    std::cout << "Elapsed time for anotherFunction(): " << duration << " seconds" << std::endl;

    // Time yetAnotherFunction()
    start = clock();
    yetAnotherFunction();
    end = clock();
    duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    std::cout << "Elapsed time for yetAnotherFunction(): " << duration << " seconds" << std::endl;

    return 0;
}
