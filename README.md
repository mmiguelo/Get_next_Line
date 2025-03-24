![# GET_NEXT_LINE](https://github.com/mmiguelo/42-project-badges/blob/main/covers/cover-get_next_line.png)

<!-------📌 Overview-------->
## 📌 Overview

The `get_next_line` project is a fundamental part of file handling in C, designed to efficiently read and return lines from a file descriptor. It dynamically manages memory while optimizing performance for various input scenarios.

----
<h2 align=left>Index</h2>

<!-- mtoc-start -->

[Features ✨](#features-) <br>
[Project Files 📂](#project-files-) <br>
[Function Prototype 🔧](#function-prototype-) <br>
[How It Works 🛠](#how-it-works-) <br>
[Utility Functions 🔗](#utility-functions-) <br>
[Memory Management 🧠](#memory-management-) <br>
[Usage ⚙️](#usage-%EF%B8%8F) <br>&nbsp;&nbsp;&nbsp;&nbsp;
[🔨 Compilation](#-compilation) <br>
[Important Notes ⚠️](#important-notes-%EF%B8%8F)


<!-- mtoc-end -->

<div/>

<div align=left>

# Features ✨

✅ Reads a file line by line.
<br>✅ Uses a dynamically adjustable buffer size.
<br>✅ Optimized memory management using static storage.
<br>✅ Custom-built utility functions for string operations.
<br>✅ Handles different edge cases, such as empty files or invalid file descriptors.
<br>
<br>

# Project Files 📂

 📜 `get_next_line.c` – Contains the core logic of the function.
<br> 🔧 `get_next_line_utils.c` – Provides helper functions for string manipulation.
<br> 📘 `get_next_line.h` – Header file defining function prototypes and macros.
<br>
<br>

## Function Prototype 🔧

```c
char *get_next_line(int fd);
```
<br>

# How It Works 🛠

1️⃣ Reads data in chunks of `BUFFER_SIZE` using `read()`.  
<br>2️⃣ Stores data in a static variable until a newline (`\n`) or EOF is encountered.  
<br>3️⃣ Extracts and returns a complete line.  
<br>4️⃣ Retains any remaining data in static storage for subsequent function calls.
<br>
<br>

# Utility Functions 🔗

🔹 `ft_strjoin` – Merges two strings while freeing the first one.
<br>🔹 `ft_strclen` – Computes the length of a string up to a specific character.
<br>🔹 `ft_strndup` – Duplicates a string up to a specified length.
<br>🔹 `ft_strchr` – Finds a character in a string.
<br>🔹 `free_data` – Handles proper memory deallocation.
<br>🔹 `save_remaining` – Saves leftover buffer content after extracting a line.
<br>🔹 `read_text` – Reads and appends data from the file descriptor.
<br>
<br>

# Memory Management 🧠

📌 The `read_text` function continuously reads from the file descriptor and appends new data to the existing storage.
<br>📌 The `save_remaining` function extracts and retains leftover content for the next function call.
<br>📌 The `free_data` function ensures no memory leaks by freeing dynamically allocated memory.
<br>
<br>

# Usage ⚙️

### 🔨 Compilation

To compile with a `BUFFER_SIZE` of 42:
```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

### 🚀 Example Usage
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
<br>

# Important Notes ⚠️

⚡ BUFFER_SIZE can be modified at compile time.
<br>⚡ Returns NULL when no more lines are available.
<br>⚡ Uses dynamic memory allocation, requiring manual free() calls.
<br>⚡ Does not support multiple file descriptors simultaneously. (YET)

<br>

## 📜 License

This project is licensed under the MIT License.

<p align="right">(<a href="#readme-top">get to top</a>)</p>
