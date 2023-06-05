# Fibonacci Calculator

This is a multi-threaded Linux program that accepts a single integer parameter from the command line and prints out the first N Fibonacci numbers to the screen.

## Requirements

- Linux operating system
- C compiler (GCC or Clang)
- POSIX Threads library (`pthread`)

## Usage

1. Clone the repository or download the source code files.

2. Compile the program using the following command:

   ```bash
   make
3. Run the program and enter a positive integer when prompted:
   ./fibonacci
4. The program will calculate and display the first N Fibonacci numbers, where N is the integer entered.

## Functionality

The Fibonacci Calculator program offers the following functionality:

- Launches a calculating thread to compute the Fibonacci numbers.
- Stores the results in a dynamically allocated array accessible by the main thread.
- Prints the Fibonacci numbers to the screen after the calculating thread completes.
- Displays the process ID and username.

