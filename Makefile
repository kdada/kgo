SOURCES=$(shell find . -name "*.cpp")
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGET=kgo
OUTPUT=bin
CXX=clang++
CXXFLAGS=-std=c++14
LDFLAGS=


.PHONY: all
all: lex $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: lex
lex:
	flex -o lex.cpp kgo.l
