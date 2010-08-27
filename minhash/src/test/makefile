PACKAGE = test_minhash_classfier
SRCS = test_minhash_classifier.cpp test_minhash_multi_classifier.cpp
PROGS = $(SRCS:.cpp=)
HEADS =  ../../include/array.hpp ../../include/minhash.hpp ../../include/minhash_classifier.hpp ../../include/minhash_multi_classifier.hpp
OBJS = $(SRCS:.cpp=.o)

LD = g++
LDLIBS = -llog4cxx

CXX = g++
CXXFLAGS = -g -Wall -I../../include

all: $(PACKAGE)

$(PACKAGE): $(PROGS)

$(PROGS): $(OBJS) makefile

.o :
	$(LD) $(LDFLAGS) $< -o $@ $(LDLIBS)

$(OBJS): $(HEADS) makefile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(PACKAGE) $(OBJS)
