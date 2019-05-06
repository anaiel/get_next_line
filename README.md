# Get_Next_Line

This project was completed in november 2018 as part of the 42 school cursus. The instructions were to create a function that would allow to read a file line after line, such as if it were called in a loop, the whole file would be printed. The exact instructions for the project can be found in the *resources* folder.

![Get_Next_line](https://i.imgur.com/9M2OsSX.png)

*File descriptors, basic parsing, bufferisation*

## Solving the problem

The most important part of the project was understanding how such a function could work when used in a program, and getting familiar with the concept of **static variables**.

The project also introduced the notion of **memory leaks**, and it becomes mandatory for get_next_line and all following projects that there should not be any memory leaks.

## Getting Started

A main is provided in order to compile an executable. The main's function is simply to call get_next_line and print the result until the end of the provided file is reached, preceded with the return value of get_next_line (1 if a line was read, 0 if the end of the file was reached, and -1 in case of error).

Run `make` to compile the libft library and the gnl executable.

## Running the tests

```
$>./gnl resources/test_file
1 : Static Variables in C
1 :
1 : Static variables have a property of preserving their value even after they are out of their scope! Hence, static variables preserve their previous value in their previous scope and are not initialized again in the new scope.
1 :
1 : Syntax:
1 : 	static data_type var_name = var_value;
1 :
1 : Following are some interesting facts about static variables in C.
1 : 1) A static int variable remains in memory while the program is running. A normal or auto variable is destroyed when a function call where the variable was declared is over.
1 : For example, we can use static int to count number of times a function is called, but an auto variable can’t be used for this purpose.
1 : 2) Static variables are allocated memory in data segment, not stack segment. See memory layout of C programs for details.
1 : 3) Static variables (like global variables) are initialized as 0 if not initialized explicitly. For example in the below program, value of x is printed as 0, while value of y is something garbage.
1 : 4) In C, static variables can only be initialized using constant literals. For example, following program fails in compilation. See this for more details.
1 : 5) Static global variables and functions are also possible in C/C++. The purpose of these is to limit scope of a variable or function to a file. Please refer Static functions in C for more details.
1 :
1 : (c) https://www.geeksforgeeks.org/static-variables-in-c/
0 X
```

## Authors

* **[anaiel](https://github.com/anaiel)**

<img align="right" src="https://i.imgur.com/vAp9aPj.png" />
