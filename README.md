![# GET_NEXT_LINE](https://github.com/mmiguelo/42-project-badges/blob/main/covers/cover-get_next_line.png)

## 📌 Overview
The `get_next_line` project is a fundamental part of file handling in C, designed to efficiently read and return lines from a file descriptor. It dynamically manages memory while optimizing performance for various input scenarios.
<br>
<br>
## ✨ Features
<br>✅ Reads a file line by line.
<br>✅ Uses a dynamically adjustable buffer size.
<br>✅ Optimized memory management using static storage.
<br>✅ Custom-built utility functions for string operations.
<br>✅ Handles different edge cases, such as empty files or invalid file descriptors.
<br>
<br>
## 📂 Project Files
<br> 📜 `get_next_line.c` – Contains the core logic of the function.
<br> 🔧 `get_next_line_utils.c` – Provides helper functions for string manipulation.
<br> 📘 `get_next_line.h` – Header file defining function prototypes and macros.
<br>
<br>
## 🔧 Function Prototype
```c
char *get_next_line(int fd);
```

<br>
<br>
## 🛠 How It Works
<br>1️⃣ Reads data in chunks of `BUFFER_SIZE` using `read()`.  
<br>2️⃣ Stores data in a static variable until a newline (`\n`) or EOF is encountered.  
<br>3️⃣ Extracts and returns a complete line.  
<br>4️⃣ Retains any remaining data in static storage for subsequent function calls.
<br>
<br>

## 🔗 Utility Functions
<br> 🔹 `ft_strjoin` – Merges two strings while freeing the first one.
<br>🔹 `ft_strclen` – Computes the length of a string up to a specific character.
<br>🔹 `ft_strndup` – Duplicates a string up to a specified length.
<br>🔹 `ft_strchr` – Finds a character in a string.
<br>🔹 `free_data` – Handles proper memory deallocation.
<br>🔹 `save_remaining` – Saves leftover buffer content after extracting a line.
<br>🔹 `read_text` – Reads and appends data from the file descriptor.
<br>
<br>

## 🧠 Memory Management
<br>📌 The `read_text` function continuously reads from the file descriptor and appends new data to the existing storage.
<br>📌 The `save_remaining` function extracts and retains leftover content for the next function call.
<br>📌 The `free_data` function ensures no memory leaks by freeing dynamically allocated memory.
<br>
<br>

## ⚙️ Usage

### 🔨 Compilation
To compile with a `BUFFER_SIZE` of 42:
```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

## 🚀 Example Usage

<p align="right">(<a href="#readme-top">get to top</a>)</p>
