# GET_NEXT_LINE

This project was completed in november 2018 as part of the 42 school cursus. The instructions were to create a function that would allow to read a file line after line, such as if it were called in a loop, the whole file would be printed. The exact instructions for the project can be found [here](https://github.com/VincentMatthys/42_GNL/blob/master/subjects/get_next_line.fr.pdf).

## Getting Started

A main is provided in order to compile an executable. Run :
```
git submodule init
git submodule update --remote --merge
```
To get the latest version of the [libft library](http://github.com/anaiel/libft).
Then run `make` to create the executable.

## Running the tests

```
./gnl test_file
```
Provided test_file is a valid file, the executable should print the content of the file. Each line is preceded with the return value of the get_next_line function (1 if get_next_line could read a line, and 0 if it got to the end of the file). It will return an error message if get_next_line returns -1 (if a memory allocation failed).

## Authors

* **Anaelle Leclabart** - [anaiel](https://github.com/anaiel)
