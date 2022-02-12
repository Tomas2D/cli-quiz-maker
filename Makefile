CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++14 -O2
LDFLAGS=
EXECUTABLE=quiz.out
SOURCES=main.cpp

.PHONY: all clean

all: $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS) $(SOURCES:.cpp=.o) -o $(EXECUTABLE) $(LDFLAGS)

clean:
	$(RM) $(SOURCES:.cpp=.o) $(EXECUTABLE)

run:
	./$(EXECUTABLE)