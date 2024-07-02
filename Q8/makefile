CXX = g++
CXXFLAGS = -std=c++11 -pthread -Wall -g

TARGET = myprogram

SRCS = Singleton.cpp DerivedSingleton.cpp Main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
