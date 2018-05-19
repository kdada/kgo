BUILDDIR=build
BINDIR=bin
SOURCEDIR=.
SOURCES=$(shell find . -name "*.cpp")
OBJECTS=$(SOURCES:$(SOURCEDIR)/%.cpp=$(BUILDDIR)/%.o)
TESTS=$(shell find . -name "*.kgo")
TARGET=$(BINDIR)/kgo
CXX=clang++
CXXFLAGS=-std=c++14 -c
LDFLAGS=


.PHONY: all
all: lex.cpp parser.cpp mkdir $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJECTS): $(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

lex.cpp: kgo.l
	@flex -o $@ $<

parser.cpp: kgo.y
	@bison --defines=parser.hpp -o $@ $<

.PHONY: mkdir
mkdir:
	@mkdir -p $(BUILDDIR) $(BINDIR)

.PHONY: test
test: $(TESTS)
	$(TARGET) $^

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)

