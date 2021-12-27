CC := clang
CXX := clang++

.PHONY: all
all:answer

objects := main.o answer.o

answer: $(objects)
	$(CXX) -o $@ $(objects)

main.o: answer.hpp
answer.o: answer.cpp

.PHONY:clean
clean:
	rm -rf answer $(objects)
