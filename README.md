# GET_NEXT_LINE

This project was completed in november 2018 as part of the 42 school cursus. The instructions were to create a function that would allow to read a file line after line, such as if it were called in a loop, the whole file would be printed. There are two versions of this function: **get_next_line.c** contains a function that only supports one file descriptor, while **get_next_line_multiplefd.c** support multiple file descriptors. The exact instructions for the project can be found [here](https://github.com/VincentMatthys/42_GNL/blob/master/subjects/get_next_line.fr.pdf).

## Getting Started

Extra files are provided in order to compile an executable. 
```
git submodule init
git submodule update --remote --merge
```
To get the latest version of the [libft library](http://github.com/anaiel/libft). Then run `make` or `make single` to create an executable than supports only one file as an argument. Run `make multiple` to create an executable that can handle multiple files.

## Running the tests

### Single fd

```
./gnl test_file
```
Provided test_file is a valid file, the executable should print the content of the file. Each line is preceded with the return of the get_next_line function (1 if get_next_line could read a line, and 0 if it got to the end of the file).

### Multiple fd

```
./gnl test_file1 test_file2 test_file3
```
Provided all test files are valid, the executable will print the first ten lines of each file (starting with the first line of each file, then the second line of each file, etc.). Each line is preceded with the return value of the get_next_line function, and the file descriptor between parenthesis.


## Authors

* **Anaelle Leclabart** - [anaiel](https://github.com/anaiel)
