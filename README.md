<h1 align="center">
	get_next_line
</h1>

*<p align="center">May it be a file, stdin, or even later a network connection, you will always need a way to read content line by line.</p>*

## Score: 125/100🎉

## Description:
A custom getline-esque function to read lines from a file.  
Each read operation uses a specified buffer size, and is called on loop until a newline (`\n`) is encountered.  
The line, including the `\n` is returned.  
If the function is called again on the same file, it returns the next line.
(Content of bonus and fandatory files are identical.)

## Usage:  
#### Prototype:
```C
char *get_next_line(int fd);
```
#### Compilation:
Include get_next_line.c, get_next_line_utils.c, and get_next_line.h in your project.  
Make sure to include `get_next_line.h` appropriately in your source code.  
Set BUFFER_SIZE to any number at compilation with `-D BUFFER_SIZE=<size>`.
```Java
//Compilation example:
gcc -D BUFFER_SIZE=42 main.c getnext_line.c get_next_line_utils.c
```
