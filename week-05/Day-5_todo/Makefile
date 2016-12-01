headers := $(wildcard *.h)
sources := $(wildcard *.cpp)
objects := $(sources:%.cpp=%.o)

todo: $(objects)
	$(CXX) $^ -o $@

%.o: %.cpp $(headers)
	$(CXX) -c -o $@ $<

.PHONY: clean
clean: 
	$(RM) todo todos.txt *.o

#objects := $(patsubst %.c,%.o,$(wildcard *.cpp))
#all: $(objects)
#	g++ -o todo $(objects)
