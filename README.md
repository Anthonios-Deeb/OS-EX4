## valgrind Q5 Analysis

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

# Helgrind Q7 Analysis

This document summarizes the race conditions detected by Helgrind in the provided multi-threaded program.

## Summary of Errors

### Data Race During Read

- **Location**: `square` function
- **Error**: Possible data race during read of size 8 at `0x119018`
- **Thread**: #4
- **Details**: 
  - Read operation at `0x108980` (`square` function)
  - Conflicts with a previous write by thread #3 at `0x108990` (`square` function)
  - Address `0x119018` is inside the data symbol `accum`
- **Reason**: The shared variable `accum` is accessed by multiple threads without synchronization, leading to a race condition.

### Data Race During Write

- **Location**: `square` function
- **Error**: Possible data race during write of size 8 at `0x119018`
- **Thread**: #4
- **Details**:
  - Write operation at `0x108990` (`square` function)
  - Conflicts with a previous write by thread #3 at `0x108990` (`square` function)
  - Address `0x119018` is inside the data symbol `accum`
- **Reason**: The shared variable `accum` is accessed and modified by multiple threads concurrently without synchronization, causing a race condition.

## Conclusion

The detected race conditions occur because multiple threads read from and write to the shared variable `accum` without proper synchronization mechanisms. To fix these issues, synchronization primitives such as mutexes should be used to ensure that only one thread can access the shared variable at a time.




