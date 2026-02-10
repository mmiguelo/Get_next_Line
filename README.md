<a id="readme-top"></a>

<div align="center">

![# GET_NEXT_LINE](https://github.com/mmiguelo/42-project-badges/blob/main/covers/cover-get_next_line.png)

# 📖 get_next_line

**Read a file line by line — one call at a time | 42 School Project**

[![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![Score](https://img.shields.io/badge/Score-100%20%2F%20100-brightgreen?style=for-the-badge)](https://github.com/mmiguelo/Get_next_Line)
[![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norminette](https://img.shields.io/badge/Norm-OK-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)

---

*A C function that returns the next line from a file descriptor each time it is called, handling any buffer size.*

</div>

---

## 📖 Table of Contents

- [About](#-about)
- [Features](#-features)
- [Function Prototype](#-function-prototype)
- [How It Works](#-how-it-works)
- [Project Files](#-project-files)
- [Utility Functions](#-utility-functions)
- [Memory Management](#-memory-management)
- [Usage](#%EF%B8%8F-usage)
  - [Compilation](#compilation)
  - [Example](#example)
- [Important Notes](#%EF%B8%8F-important-notes)
- [Author](#-author)

---

## 🧠 About

The **get_next_line** project is a fundamental exercise in file I/O and dynamic memory management in C. The goal is to write a function that, when called in a loop, returns one line at a time from a given file descriptor — including `stdin`.

This project reinforces key concepts:

- **Static variables** for state persistence across function calls
- **Dynamic memory allocation** and proper freeing strategies
- **File descriptor** reading with configurable buffer sizes
- Robust **edge case handling** (empty files, invalid FDs, variable buffer sizes)

---

## ✨ Features

| | Feature |
|:--:|:--------|
| ✅ | Reads a file **line by line**, one call at a time |
| ✅ | Supports **any `BUFFER_SIZE`** defined at compile time |
| ✅ | Uses **static storage** to retain data between calls |
| ✅ | Custom-built utility functions (no external libraries) |
| ✅ | Handles edge cases: empty files, invalid FDs, `BUFFER_SIZE` of 1 or 10000+ |

---

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
```

| Parameter | Description |
|:----------|:------------|
| `fd` | The file descriptor to read from |
| **Return** | The next line (including `\n`), or `NULL` if EOF / error |

---

## 🛠 How It Works

```
┌──────────────────────────────────────────────────────┐
│                   get_next_line(fd)                   │
├──────────────────────────────────────────────────────┤
│                                                      │
│  1️⃣  read_text()                                     │
│     Reads chunks of BUFFER_SIZE from fd              │
│     Appends to static storage until \n or EOF        │
│                        ↓                             │
│  2️⃣  Extract line                                    │
│     Copies everything up to (and including) \n       │
│     Returns this as the result                       │
│                        ↓                             │
│  3️⃣  save_remaining()                                │
│     Stores leftover data after \n in static storage  │
│     Ready for the next call                          │
│                                                      │
└──────────────────────────────────────────────────────┘
```

> The **static variable** persists between calls, so data read beyond the newline is never lost — it's simply saved for next time.

---

## 📂 Project Files

```
Get_next_Line/
├── get_next_line.c          # Core logic: read, extract, save
├── get_next_line_utils.c    # Helper functions for string ops
├── get_next_line.h          # Header: prototypes & BUFFER_SIZE
└── README.md
```

---

## 🔗 Utility Functions

<div align="center">

| Function | Description |
|:---------|:------------|
| `ft_strjoin` | Concatenates two strings, freeing the first |
| `ft_strclen` | Returns length of string up to a given character |
| `ft_strndup` | Duplicates a string up to `n` bytes |
| `ft_strchr` | Locates a character in a string |
| `free_data` | Safely frees buffer and storage to prevent leaks |
| `save_remaining` | Extracts and stores leftover content after `\n` |
| `read_text` | Reads from fd and appends to storage until `\n` or EOF |

</div>

---

## 🧹 Memory Management

The function uses a careful allocation strategy to avoid leaks:

| Function | Responsibility |
|:---------|:---------------|
| `read_text` | Allocates a read buffer, appends to storage via `ft_strjoin` (which frees the old storage) |
| `save_remaining` | Frees the full storage after extracting the leftover portion into a new allocation |
| `free_data` | Frees both the read buffer and storage on error — returns `NULL` for clean error propagation |

> 💡 Every `malloc` has a corresponding `free` — no memory is leaked on success or failure paths.

---

## ⚙️ Usage

### Compilation

Compile with a custom `BUFFER_SIZE` (replace `42` with any positive integer):

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

> If `BUFFER_SIZE` is not specified, it defaults to **42**.

### Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd = open("file.txt", O_RDONLY);
    char    *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

**Output** (for a file containing `Hello\nWorld\n`):
```
Hello
World
```

---

## ⚠️ Important Notes

| | Note |
|:--:|:-----|
| ⚡ | `BUFFER_SIZE` can be overridden at compile time with `-D BUFFER_SIZE=n` |
| ⚡ | Returns `NULL` when there are no more lines to read (EOF) |
| ⚡ | The caller is responsible for calling `free()` on each returned line |
| ⚡ | Does not support multiple file descriptors simultaneously *(yet)* |
| ⚡ | Undefined behavior if `BUFFER_SIZE` is negative or zero |

---

## 👤 Author

**mmiguelo** — 42 Student

[![GitHub](https://img.shields.io/badge/GitHub-mmiguelo-181717?style=for-the-badge&logo=github)](https://github.com/mmiguelo)

---

<div align="center">

*Made with ❤️ at 42*

<p>(<a href="#readme-top">⬆️ back to top</a>)</p>

</div>
