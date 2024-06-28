# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic -O3

# Source files
SRCS = main.cpp vectorList_graph.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = main

# Default target
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove object files and executable
clean:
	rm -f $(OBJS) $(TARGET) *.gcno *.gcda gmon.out callgrind.out.* coverage.info -r out

# Code coverage target
coverage: CXXFLAGS += -fprofile-arcs -ftest-coverage
coverage: clean $(TARGET)
	./$(TARGET) -e 10 -v 5 -s 42
	gcov $(SRCS)

# Profiling target with gprof
profile: CXXFLAGS += -pg
profile: clean $(TARGET)
	./$(TARGET) -e 2500 -v 1000 -s 42
	gprof $(TARGET) gmon.out > analysis.txt

# Valgrind memory check target
valgrind-memcheck: clean $(TARGET)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(TARGET) -e 10 -v 5 -s 42

# Valgrind callgrind target
valgrind-callgrind: clean $(TARGET)
	valgrind --tool=callgrind ./$(TARGET) -e 10 -v 5 -s 42
	callgrind_annotate callgrind.out.* > callgraph.txt

.PHONY: all clean coverage profile valgrind-memcheck valgrind-callgrind
