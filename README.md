**Project: Stacks and Queues in C
This project implements the stack and queue data structures in C and provides an interpreter that reads instructions from a file and calls the appropriate functions to perform them. The program is designed to work with Monty ByteCodes files, which are scripts written in the Monty scripting language.
The code will be compiled using the following command:

$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

The Monty Language
Monty 0.98 is a scripting language that first compiles scripts into Monty byte codes, similar to how Python works. It operates on a unique stack with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

The monty Program
Usage: monty file

The file argument represents the path to the file containing Monty byte code instructions. The interpreter will read the instructions from this file and execute them accordingly.

Feel free to refer to this README.md file whenever you need to understand the project's goals, the Monty language, or the proper usage of stacks and queues in C. Good luck with your implementation!
