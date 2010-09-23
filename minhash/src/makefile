PACKAGE = minhash_demo
SRCS = main.cpp
HEADS = ../include/array.hpp ../include/minhash.hpp ../include/multi_minhash.hpp ../include/minhash_multi_classifier.hpp
OBJS = $(SRCS:.cpp=.o)
FILES = $(SRCS) $(HEADS)
VERSION = 0.1

LD = g++
LDLIBS = -llog4cxx

CXX = g++
CXXFLAGS = -g -Wall -I../include

.SUFFIXES:
.SUFFIXES: .o .cpp .hpp

all: $(PACKAGE)

$(PACKAGE): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

$(OBJS): $(HEADS) makefile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(PACKAGE) $(OBJS)
