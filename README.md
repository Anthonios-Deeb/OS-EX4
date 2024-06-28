## valgrind Q5 Report

### Conditional jump or move depends on uninitialized value(s)
- **Location**: `hello.c:16`
- **Line of Code**: `if (string_so_far != (char *)0)`
- **Description**: This error occurs due to using an uninitialized value (`string_so_far`) during a conditional statement.

### Use of uninitialized value of size 8
- **Location**: `hello.c:17`
- **Line of Code**: `strcpy(string, string_so_far);`
- **Description**: Valgrind detected the use of an uninitialized value (`string_so_far`) during a call to `strcpy`. This can lead to reading from or writing to unexpected memory locations.

### Invalid write of size 2
- **Location**: `hello.c:22`
- **Line of Code**: `strcat(string, " ");`
- **Description**: This error indicates an attempt to write data beyond the allocated memory block (`string`), which can corrupt memory and lead to program crashes.

### Invalid read of size 1
- **Location**: `hello.c:17`
- **Line of Code**: `strcpy(string, string_so_far);`
- **Description**: Valgrind detected an attempt to read from an invalid memory address during a call to `strcpy`, which can result in unpredictable program behavior.

### Memory leaks
- **Location**: `hello.c:13`
- **Line of Code**: `string = malloc(length + 1);`
- **Description**: Valgrind reported memory leaks totaling 122 bytes in 6 blocks.
