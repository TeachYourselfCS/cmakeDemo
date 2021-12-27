CC := clang
CXX := clang++


.PHONY: all
all:hello

objects = hello.o

hello:$(objects)
	$(CXX) -o $@ $(objects)

hello.o:hello.cpp
	$(CXX) -c hello.cpp

.PHONY:clean
clean:
	rm -rf hello $(objects)
