# MONTY INTERPRETER
<img src="https://i.imgur.com/93Rf9Nm.png" width=100%>
## Introduction
In this collaborate project between Diego Varela and Toshi Borgia we created a Monty Interpreter capable of processing Monty byte codes with varios opcodes.
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
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
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
## Table of Contents
-  [Introduction](https://github.com/DiegoSusviela/simple_shell/blob/main/README.md#description)
-  [Getting Started](https://github.com/DiegoSusviela/simple_shell/blob/main/README.md#getting-started)
	-  [Task Requirments](https://github.com/DiegoSusviela/simple_shell/blob/main/README.md#task-requirements)
	- [Instalation](https://github.com/DiegoSusviela/simple_shell/blob/main/README.md#instalation)
	-  [EXAMPLES](https://github.com/DiegoSusviela/simple_shell/blob/main/README.md#examples)
-  [File Contents](https://github.com/DiegoSusviela/simple_shell/blob/main/README.md#file-contents)
-  [Builtin Commands](https://github.com/DiegoSusviela/simple_shell/blob/main/README.md#builtins-commands)
-  [Extras](https://github.com/DiegoSusviela/simple_shell/blob/main/README.md#extras)
-  [**Authors**](https://github.com/DiegoSusviela/simple_shell/blob/main/README.md#authors)
##
-   Any outputs are printed on  `stdout`
-   Any error message are printed on  `stderr`
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
