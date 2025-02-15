# Pipex  
[42 Cursus] A C program that mimics the behavior of shell pipes (`|`), allowing you to execute commands in a pipeline with input and output redirection.  
This project was designed to enhance skills in **process management**, **file handling**, and **C programming**.

Keywords  
- **Pipes** 
- **Process Management**
- **File Descriptors**
- **Error Handling**
- **Input/Output Redirection**
- **Shell Commands**
- **Forking**
- **System Calls**

---

## Index

- [Overview](#overview)
- [Features](#features)
- [Bonus Features](#bonus-features)
- [Functions Allowed](#functions-allowed)
- [How It Works](#how-it-works)
  - [Example Usage](#example-usage)
  - [Bonus Usage](#bonus-usage)
  - [Error Handling Examples](#error-handling-examples)
- [What I Learned](#what-i-learned)
- [Installation](#installation)
- [Author](#author)
- [Acknowledgments](#acknowledgments)

---

## Overview  
The `pipex` project is a C program that simulates the behavior of shell pipes (`|`). It takes four arguments: two file names and two shell commands. The program executes the commands in a pipeline, redirecting the input and output as specified. This project was created to deepen understanding of Unix process management, file handling, and error handling in C.  

---

## Features  
- **Pipeline Execution**: Execute shell commands in a pipeline, similar to the `|` operator in Unix shells.  
- **Input/Output Redirection**: Redirect input from a file and output to another file using file descriptors.  
- **Error Handling**: Gracefully handle errors, ensuring no unexpected crashes or memory leaks.  
- **Basic Command Support**: Support for shell commands with arguments.  
- **Memory Management**: clean and efficient.

## Bonus Features  
- **Multiple Pipes**: Handle more than two commands in a pipeline (e.g., `cmd1 | cmd2 | cmd3`).  
- **Here Document**: Support for `<<` and `>>` redirection when the first parameter is `here_doc`.  
- **Advanced Error Handling**: Improved error messages and handling for edge cases.  

---

## Functions Allowed

The following functions are authorized for use in the `pipex` project. Each function is briefly described to explain its purpose and relevance to the project.

### 1. **File Handling**
- **`open()`**: Opens a file and returns a file descriptor. Used to read from or write to files.
- **`close()`**: Closes a file descriptor, freeing up resources.
- **`unlink()`**: Deletes a file from the filesystem. Useful for cleaning up temporary files.

### 2. **Process Management**
- **`fork()`**: Creates a new process by duplicating the calling process. Used to execute commands in child processes.
- **`execve()`**: Replaces the current process image with a new one. Used to execute shell commands.
- **`wait()`**: Waits for a child process to terminate. Useful for synchronizing parent and child processes.
- **`waitpid()`**: Waits for a specific child process to terminate. Provides more control than `wait()`.

### 3. **Pipes**
- **`pipe()`**: Creates a pipe, which is a unidirectional data channel for inter-process communication. Used to connect commands in a pipeline.
- **`dup()`**: Duplicates a file descriptor. Useful for redirecting input/output.
- **`dup2()`**: Duplicates a file descriptor and assigns it to a specified file descriptor number. Used to redirect input/output to/from pipes.

### 4. **Memory Management**
- **`malloc()`**: Allocates memory on the heap. Used for dynamic memory allocation.
- **`free()`**: Deallocates memory previously allocated by `malloc()`. Prevents memory leaks.

### 5. **Error Handling**
- **`perror()`**: Prints an error message to `stderr` based on the current value of `errno`. Useful for debugging.
- **`strerror()`**: Returns a string describing the error code stored in `errno`. Useful for generating custom error messages.

### 6. **Input/Output**
- **`read()`**: Reads data from a file descriptor into a buffer. Used to read input from files or pipes.
- **`write()`**: Writes data from a buffer to a file descriptor. Used to write output to files or pipes.

### 7. **Program Control**
- **`exit()`**: Terminates the program with a specified status code. Used to handle errors or normal termination.
- **`access()`**: Checks if a file exists or if the program has permission to access it. Useful for error handling.

### 8. **Custom Functions**
- **`ft_printf()`**: A custom implementation of `printf` (if you have coded one). Used for formatted output.

---

## How It Works  
The program takes four arguments: two file names and two shell commands. It executes the commands in a pipeline, redirecting the input and output as specified.

### Example Usage  
```bash
./pipex infile "ls -l" "wc -l" outfile
```  
This behaves the same as the following shell command:  
```bash
< infile ls -l | wc -l > outfile
```

| **Input Command**                                      | **Description**                                                                 | **Expected Output**                                                                 |
|--------------------------------------------------------|---------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| `./pipex infile "ls -l" "wc -l" outfile`               | Lists files in `infile` directory and counts lines.                             | Number of lines from `ls -l` written to `outfile`.                                 |
| `./pipex infile "grep a1" "wc -w" outfile`             | Searches for lines containing "a1" in `infile` and counts words.                | Number of words in lines containing "a1" written to `outfile`.                     |
| `./pipex infile "cat" "wc -c" outfile`                 | Outputs the content of `infile` and counts characters.                          | Number of characters in `infile` written to `outfile`.                             |
| `./pipex infile "echo Hello" "tr 'a-z' 'A-Z'" outfile` | Echoes "Hello" and converts it to uppercase.                                    | `HELLO` written to `outfile`.                                                      |
| `./pipex infile "sort" "uniq" outfile`                 | Sorts the content of `infile` and removes duplicate lines.                      | Sorted and deduplicated content written to `outfile`.                              |
| `./pipex infile "cut -d: -f1" "sort" outfile`          | Extracts the first field from `infile` (colon-separated) and sorts it.          | Sorted list of first fields written to `outfile`.                                  |
| `./pipex infile "awk '{print $1}'" "wc -l" outfile`    | Extracts the first column from `infile` and counts lines.                       | Number of lines in the first column written to `outfile`.                          |
| `./pipex infile "sed 's/foo/bar/'" "wc -c" outfile`    | Replaces "foo" with "bar" in `infile` and counts characters.                    | Number of characters after replacement written to `outfile`.                       |
| `./pipex infile "head -n 5" "tail -n 1" outfile`       | Extracts the first 5 lines of `infile` and then the last line of those 5.       | The 5th line of `infile` written to `outfile`.                                     |
| `./pipex infile "tr ' ' '\n'" "sort" outfile`          | Splits words in `infile` by spaces and sorts them.                              | Sorted list of words written to `outfile`.                                         |

### Bonus Usage  
For multiple pipes:  
```bash
./pipex infile "cmd1" "cmd2" "cmd3" outfile
```  

For here document:  
```bash
./pipex here_doc LIMITER "cmd" "cmd1" outfile
```  

| **Input Command**                                      | **Description**                                                                 | **Expected Output**                                                                 |
|--------------------------------------------------------|---------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| `./pipex infile "cmd1" "cmd2" "cmd3" outfile`          | Executes three commands in a pipeline.                                          | Output of `cmd3` written to `outfile`.                                             |
| `./pipex here_doc LIMITER "cmd" "cmd1" outfile`        | Uses `here_doc` to read input until `LIMITER` is found, then processes it.      | Output of `cmd1` appended to `outfile`.                                            |

### Error Handling Examples

| **Input Command**                                      | **Description**                                                                 | **Expected Output**                                                                 |
|--------------------------------------------------------|---------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| `./pipex non_existent_file "ls -l" "wc -l" outfile`    | Tries to read from a non-existent file.                                         | Error message: `Error: No such file or directory`.                                 |
| `./pipex infile "invalid_cmd" "wc -l" outfile`         | Tries to execute an invalid command.                                            | Error message: `Error: Command not found`.                                         |
| `./pipex infile "ls -l" "wc -l" unwritable_file`       | Tries to write to an unwritable file.                                           | Error message: `Error: Permission denied`.                                         |

---

## What I Learned  
- **Process Management**: Using `fork()`, `execve()`, and `waitpid()` to manage processes.  
- **File Descriptors**: Working with `open()`, `close()`, `dup()`, and `dup2()` to handle input/output redirection.  
- **Pipes**: Creating and managing pipes with `pipe()` to connect processes.  
- **Error Handling**: Ensuring robust error management to avoid crashes and memory leaks.  
- **C Programming**: Writing clean, efficient, and maintainable C code.  

---

## Installation  
### Requirements  
- A C compiler
- Standard libraries.  

### How to Run  
1. Clone this repository:  
   ```bash  
   git clone https://github.com/yourusername/pipex.git  
   cd pipex  
   ```  
2. Compile the project using the provided **Makefile**:  
   ```bash  
   make  
   ```  
3. Run the program with the required arguments:  
   ```bash  
   ./pipex infile "cmd1" "cmd2" outfile
   ```  

For bonus features, use the bonus rule in the Makefile:  
   ```bash  
   make bonus
   ```  

---

## Author  
- **Name**: Oliver King Zamora  
- **GitHub**: [oliverkingz](https://github.com/oliverkingz)  
- **42 Login**: ozamora-  

---

## Acknowledgments  
This project is part of the **42 Cursus**, a rigorous programming curriculum that emphasizes hands-on learning and problem-solving. Special thanks to the 42 team for providing this challenging and rewarding project!  
