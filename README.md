# get_next_line

## Description  
**get_next_line** is a function that reads a line from a file descriptor (fd) one at a time, including the newline character (`\n`). This project aims to deepen the understanding of file handling, dynamic memory allocation, and buffer management in C.  

## Features  
- Reads from a file descriptor one line at a time.  
- Supports any valid file descriptor, including standard input (`STDIN`).  
- Manages buffers efficiently to optimize reading performance.  
- Works with dynamic memory allocation to handle long lines.  

## Function Prototype  
```c
char *get_next_line(int fd);
```

## Implementation Details  
- Uses `read` to fetch data from the file descriptor.  
- Stores leftover data between function calls to handle multiline files.  
- Allocates memory dynamically to return the full line.  

## Installation  
Compile your project with `get_next_line.c` and `get_next_line_utils.c` :  
```sh
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o my_program
```

Or, for the bonus version, compile your project with `get_next_line_bonus.c` and `get_next_line_utils_bonus.c` :  
```sh
gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -o my_program
```

## Usage  
Include the header file in your project:  
```c
#include "get_next_line.h"
```
Example usage:  
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Notes  
- The buffer size is defined by `BUFFER_SIZE`, which can be modified at compilation (`-D BUFFER_SIZE=42`).  
- Returns `NULL` when the end of the file is reached or if an error occurs.
