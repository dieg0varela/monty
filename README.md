# MONTY INTERPRETER
<img src="https://i.imgur.com/93Rf9Nm.png" width=100%>

## Introduction
In this collaborate project between Diego Varela and Toshi Borgia we created a Monty Interpreter capable of processing Monty byte codes with various opcodes.

## Table of Contents
-  [Introduction](https://github.com/dieg0varela/monty/blob/main/README.md#introduction)
-  [Getting Started](https://github.com/dieg0varela/monty/blob/main/README.md#getting-started)
	- [Compilation and Output](https://github.com/dieg0varela/monty/blob/main/README.md#compilation--output)
	- [History of the Monty Language](https://github.com/dieg0varela/monty/blob/main/README.md#compilation--output)
-  [File Contents](https://github.com/dieg0varela/monty/blob/main/README.md#file-contents)
-  [Opcodes](https://github.com/dieg0varela/monty/blob/main/README.md#opcode-commands)
-  [**Authors**](https://github.com/dieg0varela/monty/blob/main/README.md#authors)
## Getting Started
## Compilation & Output
-   If you wish to install this you will need to have Linux OS or a virtual machine, and can run Gcc >= 4.8.4.
-   `git clone https://github.com/dieg0varela/monty.git`
-   `$ cd monty
-   Your code will be compiled this way:

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

```
Then just run the program with the .m file, for example:
`$ ./monty test.m`
-   Any output would be printed on  `stdout`
-   Any error message would be printed on  `stderr`

## The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
/monty$
```

Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not taken into account:

```
/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
/monty$
```
## The monty program
-  Usage:  `monty file`
    -   where  `file`  is the path to the file containing Monty byte code
-   If the user does not give any file or more than one argument to your program, print the error message  `USAGE: monty file`, followed by a new line, and exit with the status  `EXIT_FAILURE`
-   If, for any reason, it’s not possible to open the file, print the error message  `Error: Can't open file <file>`, followed by a new line, and exit with the status  `EXIT_FAILURE`
    -   where  `<file>`  is the name of the file
-   If the file contains an invalid instruction, print the error message  `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status  `EXIT_FAILURE`
    -   where  is the line number where the instruction appears.
    -   Line numbers always start at 1
-   The monty program runs the bytecodes line by line and stop if either:
    -   it executed properly every line of the file
    -   it finds an error in the file
    -   an error occured
-   If you can’t malloc anymore, print the error message  `Error: malloc failed`, followed by a new line, and exit with status  `EXIT_FAILURE`.
-   You have to use  `malloc`  and  `free`

## File Contents
This repository contains the following files:
File | Description 
------------ | ------------- 
  **main.c** | main function for the interpreter 
  **monty.h** | header file
  **opcodes_0-2.c** | file contatinig all the functions from task 0 to 2
  **opcodes_3-7.c** | file contatinig all the functions from task 3 to 7
  **opcodes_8-13.c** | file contatinig all the functions from task 8 to 13
  **opcodes_14.c** | file contatinig all the functions from task 14
  **freedlist.c** | function that frees a double linked list
  **test.m** | test file for the program
  **bf folder** | Brainfuck language files are here
  **monty** | compiled program for usage
  **README.md** | README file
  
## Opcode Commands

**Opcode** | **Description**
------------ | ------------- 
push | pushes an element to the stack.
pall | prints all the values on the stack, starting from the top of the stack.
pint | prints the value at the top of the stack, followed by a new line.
pop | removes the top element of the stack.
swap | swaps the top two elements of the stack.
add | adds the top two elements of the stack.
nop | doesn’t do anything.
sub | subtracts the top element of the stack from the second top element of the stack.
div | divides the second top element of the stack by the top element of the stack.
mul | multiplies the second top element of the stack with the top element of the stack.
mod | computes the rest of the division of the second top element of the stack by the top element of the stack.
comments | When the first non-space character of a line is #, treat this line as a comment (don’t do anything).
pchar | prints the char at the top of the stack, followed by a new line.
pstr | prints the string starting at the top of the stack, followed by a new line.
rotl | rotates the stack to the top.
rotl | rotates the stack to the bottom.


## Authors
- [**Diego**](https://github.com/dieg0varela) <2806@holbertonschool.com>
- [**Toshi**](https://github.com/toshi-uy) <2785@holbertonschool.com>
