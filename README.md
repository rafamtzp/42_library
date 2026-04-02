
# 42 Library

*These projects (libft, ft_printf, get_next_line) have been created as part of the 42 curriculum by ramarti2.*

---

## 📖 Description

This repository is a **combined library project** that consolidates three foundational 42 curriculum projects into a single, reusable codebase:

* **libft**
* **ft_printf**
* **get_next_line**

Although they are grouped here for convenience and reuse, these were originally **three independent projects**, each with its own objectives, constraints, and evaluations.

This repository reflects a structured and modular approach to C development, emphasizing:

* Code reuse
* Maintainability
* Clean project organization

---

## 📦 Project Breakdown

### 🧱 libft

**libft** is a custom implementation of standard C library functions, along with additional utility functions.  This was the very first project I did at 42 in milestone 0.

#### Goals:

* Recreate common libc functions from scratch
* Build a solid foundation in C programming
* Understand memory management and string manipulation

#### Features:

* String functions (`ft_strlen`, `ft_strdup`, etc.)
* Memory functions (`ft_memcpy`, `ft_memset`, etc.)
* Linked list utilities
* Character checks and conversions

#### Functions:
##### int <-> string conversion functions
* ft_atoi, ft_itoa
##### "What is it?" functions
* ft_isalnum, ft_isalpha, ft_isascii, ft_isdigit, ft_isprint
##### Memory handling functions
* ft_calloc, ft_memcmp, ft_bzero, ft_memchr, ft_memcpy, ft_memmove, ft_memset
##### put<type> functions (print different data types to stdout)
* ft_putchar_fd, ft_putendl_fd, ft_putnbr_fd, ft_putstr
##### String manipulation functions
* ft_strncmp, ft_striteri, ft_split, ft_strchr, ft_strdup
* ft_strjoin, ft_strmapi, ft_strnstr, ft_strrchr, ft_strtrim
* ft_substr, ft_strlcat, ft_strlcpy, ft_strlen
* ft_tolower, ft_toupper (these manipulate a single char)
##### Linked list functions (bonus)
* ft_lstsize, ft_lstadd_front, ft_lstadd_back, ft_lstiter
* ft_lstdelone, ft_lstclear, ft_lstnew, ft_lstlast, ft_lstmap
---

### 🖨️ ft_printf

**ft_printf** is a reimplementation of the standard `printf` function.  This project was a part of milestone 1.

#### Goals:

* Understand variadic functions (functions with optional arguments)
* Handle formatted output
* Manage parsing logic

#### Features:

* Supports common format specifiers:

  * `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`
* Modular parsing system
* Custom formatting logic

---

### 📡 get_next_line

**get_next_line** is a function that reads a file descriptor line by line. The function returns a single line read from a file.  Next time you call it, it returns the next line and so on until it's done reading from the file.

This project was also part of milestone 1.

#### Goals:

* Learn static variables and buffer management
* Handle file I/O efficiently
* Manage memory across multiple function calls

#### Features:

* Reads one line at a time from a file descriptor
* Works with multiple file descriptors simultaneously (bonus version inside gnl_bonus/)
* Efficient buffering system

Note: Both the base and bonus versions of get_next_line are present in the repository inside ./get_next_line/gnl/ and ./get_next_line/gnl_bonus, respectively.  By default, running `make` will only compile the bonus version.

---

## ⚙️ Instructions

### 🛠️ Compilation

To compile the full library:

```bash
make
```

This will generate:

```bash
libft.a
```

---

### 🧩 Project Structure

```
.
├── libft/            # Original libft project
├── ft_printf/        # ft_printf implementation
├── get_next_line/    # get_next_line (including bonus)
├── obj/              # Compiled object files (temporary)
└── other/			  # folder where I can add extra functions to expand my library
├── Makefile
└── README.md
```

---

### 📚 Usage

Include the header in your project:

```c
#include "libft.h"
```

Compile with:

```bash
cc main.c libft.a
```

---

### 🧹 Makefile Rules

```bash
make        # build library
make clean  # remove object files
make fclean # remove objects + library
make re     # rebuild everything
```

---

## 🧠 Concepts Learned

Across these three projects, the following core programming concepts were developed:

* Low-level memory management
* Static variables and state handling
* Variadic functions
* File descriptors and I/O
* Modular code design
* Algorithmic thinking and parsing logic

---

## 📚 Resources

### C Programming

* Standard C Library documentation (`man` pages)
* Internet articles on Variadic functions (`stdarg.h`)

---

## 🚀 Final Notes

This repository demonstrates progression through key foundational C projects at 42. Each module reflects a deeper understanding of system-level programming and reinforces best practices in code organization and reusability.

While unified here, each component was built independently — showcasing the ability to tackle different types of low-level programming challenges.

---