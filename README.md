# ft_printf
42 C: printf

A simple printf clone written in Norm-compliant C.

# Building
To build our project, make sure to recursively clone the submodules by passing `--recurse`.
Other than that, simple run `make` in the project's root. This will make the `libftprintf.a` library file.

# Modularity
This printf, writes through a writer struct, in order to allow for modular printf derivatives.
This allows us to write not only to the output, but also to: files, strings, sockets, mail pidgeons, etc!
A writer looks like this:
```c
struct {
    / How many bytes we wrote
    |                      / A reference to the state pointer
    |                      |            / The string  / The string length
    v                      v            v             v
  ssize_t  (*write)(void *state, char *str, size_t length);
  
  // Internal state to be passed to the write call.
  void  *state;
};
```
# Functions
### I/O
```c
// Writes to standard output (is call to fprintf)
int ft_printf(char *fmt, ...);

// Writes to a file descriptor.
int ft_fprintf(int fd, char *fmt, ...);
```


### Strings
```c
// Writes to a string see example 1.
int ft_aprintf(char **dest, char *fmt, ...);

// TODO
int ft_sprintf(char *dest, char *fmt, ...);

// TODO
int ft_snprintf(char **dest, size_t len, char *fmt, ...);
```

# Examples
### Example 1.
```c
char *str;

str = NULL;
ft_aprintf(&str, "Hello, %s", "world!");
// `str' will now have `Hello, world!'
```

# Tests
No testing suite is currently implemented.
