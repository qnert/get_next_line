# Get Next Line

This project implements a `get_next_line` function in C that reads a single line from a file descriptor each time it is called, supporting sequential calls to read through a file or standard input line-by-line. This function replicates certain functionalities of the `getline` function in standard libraries but adheres to specific project requirements and constraints.

---

## Features

- **Single Line Retrieval**: The `get_next_line` function retrieves one line at a time from a specified file descriptor, including the newline character (`\n`) if present. If the end of the file is reached without a newline, it returns the remaining content.
- **Memory Management**: Efficient memory usage is emphasized, and memory leaks are disallowed. All dynamically allocated memory must be freed appropriately.
- **Modifiable Buffer Size**: The buffer size for each `read` operation is defined by the `BUFFER_SIZE` macro, which can be set at compile time (e.g., `-D BUFFER_SIZE=42`).
- **Standard Input Compatibility**: The function is compatible with standard input, making it flexible for various input sources.

---

## Project Requirements

- **Programming Language**: C
- **Standards Compliance**: Code must adhere to the project’s Norm (specific style and formatting rules).
- **Error Handling**: The function should handle unexpected errors, such as segmentation faults or memory errors, excluding undefined behaviors.
- **Memory Leaks**: All heap-allocated memory must be properly freed to prevent leaks.
- **Compilation Requirements**: 
  - A `Makefile` should be provided with targets `all`, `clean`, `fclean`, `re`, and `bonus`.
  - Compilation flags: `-Wall -Wextra -Werror`
  - The function must work with various `BUFFER_SIZE` values, including extremely small or large sizes.
  
---

## Implementation Notes

- **Static Variables**: Static variables are encouraged to help retain data across function calls without using global variables, which are disallowed.
- **Helper Functions**: Helper functions are organized in `get_next_line_utils.c` to streamline code structure.
- **Undefined Behaviors**: The function behavior is undefined if:
  - The file content changes after a previous call to `get_next_line`.
  - A binary file is read.
- **Efficiency Considerations**: The function should read only as much data as necessary to return one line at a time. It should avoid reading the entire file at once.

---

## Forbidden

- **No Libft Usage**: This project should not utilize functions from the Libft library.
- **No `lseek()`**: The use of `lseek()` is prohibited.
- **No Global Variables**: Global variables are not allowed; static variables are suggested as an alternative.

---

## Usage

Compile the project with a specified buffer size (example with buffer size 42):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
