
# Push_Swap

## Introduction

`push_swap` is a highly efficient sorting algorithm project that challenges the developer to sort data on a stack, using a limited set of instructions, and with a goal of minimizing the number of operations used. This project is designed to teach fundamental algorithms and data structures, with a focus on stack operations and sorting algorithms under constrained conditions.

## Project Description

The `push_swap` project consists of two main parts: `push_swap` and `checker`. The `push_swap` program calculates and displays on the standard output the smallest script in the form of a list of instructions that sort the stack `a`, with the smallest number at the top. The `checker` program, on the other hand, takes integer arguments and reads instructions on the standard input. Once the instructions have been read, `checker` executes them and then determines if the integers are indeed sorted.

### Features

- Efficient sorting of integers using a custom algorithm.
- Execution of a script of actions to sort the stack, optimizing for the minimal number of operations.
- Validation of the sorting operation through a separate checker program.
- Handling of various edge cases and error management for invalid inputs.

## Getting Started

### Prerequisites

To compile and run `push_swap` and `checker`, you will need:

- A C compiler (GCC or Clang recommended)
- Make (optional, for using the Makefile included in the project)

### Compilation

The project comes with a Makefile that compiles both `push_swap` and `checker`. To compile, run the following command in the root of the project directory:

```bash
make
make bonus
```

This will create two executable files: `push_swap` and `checker`.

### Usage

To use `push_swap`, provide a list of integers as arguments:

bashCopy code

```bash
./push_swap 2 1 3 6 5 8
``` 

This will output a list of operations that sort the stack, such as `ra`, `pb`, `sa`, and so on.

To verify the sorting script with `checker`, you can pipe the output of `push_swap` into `checker` along with the same list of integers:


``` bash
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
``` 

`checker` will output `OK` if the stack is sorted, or `KO` if it is not.
