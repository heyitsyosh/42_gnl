<h1 align="center">
	get_next_line
</h1>

*<p align="center">May it be a file, stdin, or even later a network connection, you will always need a way to read content line by line.</p>*

## Description:
A custom getline-esque function to read lines from a file.  
It reads data on a loop using a configurable buffer size until it encounters a newline (`\n`).  
The line, including the `\n` is returned.  
If the function is called again on the same file, it returns the next line.

## Usage:  
#### Prototype:
```C
char *get_next_line(int fd);
```
#### Compilation:
Include source files *(get_next_line.c, get_next_line_utils.c)* when compiling your project.  
Make sure to include `get_next_line.h` appropriately in your source code.  
Set `BUFFER_SIZE` to any number at compilation with `-D BUFFER_SIZE=<size>`.

A sample `main.c` is included in this repository.  
Use the compilation example below to see a demonstration of get_next_line.
```Java
gcc -D BUFFER_SIZE=42 main.c getnext_line.c get_next_line_utils.c -o fileprinter
```
