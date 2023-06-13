#include <iostream>
#include <chrono>

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
    // Start the timer for someFunction()
    auto startTime = std::chrono::high_resolution_clock::now();

    // Call the function to be timed
    someFunction();

    // End the timer and calculate the duration
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    // Print the duration
    std::cout << "Elapsed time for someFunction(): " << duration << " milliseconds" << std::endl;

    // Start the timer for anotherFunction()
    startTime = std::chrono::high_resolution_clock::now();

    // Call the function to be timed
    anotherFunction();

    // End the timer and calculate the duration
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    // Print the duration
    std::cout << "Elapsed time for anotherFunction(): " << duration << " milliseconds" << std::endl;

    // Start the timer for yetAnotherFunction()
    startTime = std::chrono::high_resolution_clock::now();

    // Call the function to be timed
    yetAnotherFunction();

    // End the timer and calculate the duration
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    // Print the duration
    std::cout << "Elapsed time for yetAnotherFunction(): " << duration << " milliseconds" << std::endl;

    return 0;
}
