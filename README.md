
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

**libft** is a custom implementation of standard C library functions, along with additional utility functions.

#### Goals:

* Recreate common libc functions from scratch
* Build a solid foundation in C programming
* Understand memory management and string manipulation

#### Features:

* String functions (`ft_strlen`, `ft_strdup`, etc.)
* Memory functions (`ft_memcpy`, `ft_memset`, etc.)
* Linked list utilities
* Character checks and conversions

---

### 🖨️ ft_printf

**ft_printf** is a reimplementation of the standard `printf` function.

#### Goals:

* Understand variadic functions
* Handle formatted output
* Manage complex parsing logic

#### Features:

* Supports common format specifiers:

  * `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`
* Modular parsing system
* Custom formatting logic

---

### 📡 get_next_line

**get_next_line** is a function that reads a file descriptor line by line.

#### Goals:

* Learn static variables and buffer management
* Handle file I/O efficiently
* Manage memory across multiple function calls

#### Features:

* Reads one line at a time from a file descriptor
* Works with multiple file descriptors simultaneously (bonus)
* Efficient buffering system

---

## ⚙️ Instructions

### 🛠️ Compilation

To compile the full library:

```bash id="d2w8sa"
make
```

This will generate:

```bash id="a1x7kp"
libft.a
```

---

### 🧩 Project Structure

```id="r3k9tm"
.
├── libft/            # Original libft project
├── ft_printf/        # ft_printf implementation
├── get_next_line/    # get_next_line (including bonus if present)
├── obj/              # Compiled object files (temporary)
└── other/			  # folder where I can add extra functions to expand my library
├── Makefile
└── README.md
```

---

### 📚 Usage

Include the header in your project:

```c id="c9x2ls"
#include "libft.h"
```

Compile with:

```bash id="p4z7vd"
cc main.c libft.a
```

---

### 🧹 Rules

```bash id="m8q2yf"
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
* Memory management and pointers
* Variadic functions (`stdarg.h`)

### Project-Specific Topics

* String and memory manipulation (libft)
* Formatted output and parsing (ft_printf)
* File reading and buffering (get_next_line)

---

## 🚀 Final Notes

This repository demonstrates progression through key foundational C projects at 42. Each module reflects a deeper understanding of system-level programming and reinforces best practices in code organization and reusability.

While unified here, each component was built independently — showcasing the ability to tackle different types of low-level programming challenges.

---