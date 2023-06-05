#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

// Alex Boswell
// Student ID: 301261407

/*
 * Multi-threaded Linux program that accepts a single integer parameter (N)
 * from the command line and prints out the first N Fibonacci numbers to the screen.
 */

int *fibonacciNumbers; // Global variable to store Fibonacci numbers

void calculateFibonacci(int n) {
    // Calculate Fibonacci numbers and store them in the dynamically allocated array
    if (n == 1) {
        fibonacciNumbers[0] = 1; // First value is 1
    } else if (n == 2) {
        fibonacciNumbers[0] = 1; // First value is 1
        fibonacciNumbers[1] = 1; // Second value is 1
    } else {
        fibonacciNumbers[0] = 1; // Set initial 2 values
        fibonacciNumbers[1] = 1;

        for (int i = 2; i < n; i++) {
            fibonacciNumbers[i] = fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2];
        }
    }

    pthread_exit(0);
}

void printFibonacci(int n) {
    // Print the Fibonacci numbers to the screen
    for (int i = 0; i < n; i++) {
        printf("%d\n", fibonacciNumbers[i]);
    }
}

int main(int argc, char *argv[]) {
    int num;

    printf("Please enter a positive integer: ");
    scanf("%d", &num);

    // Validate user input
    while (num <= 0) {
        printf("Sorry, the integer you entered is not valid, please try again: ");
        scanf("%d", &num);
    }

    printf("\nPID is: %d \tUsername: %s\n", getpid(), getlogin());

    fibonacciNumbers = (int *) malloc(num * sizeof(int)); // Dynamically allocate memory for the array

    // Check if memory allocation was successful
    if (fibonacciNumbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    pthread_t tid; // Thread ID
    pthread_attr_t attr;

    pthread_attr_init(&attr); // Initialize thread attributes
    pthread_create(&tid, &attr, (void *) calculateFibonacci, (void *) num);
    pthread_join(tid, NULL); // Wait for the thread to complete

    printFibonacci(num);

    free(fibonacciNumbers); // Free dynamically allocated memory

    return 0;
}