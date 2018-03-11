CC=g++

.PHONY: all clean run

all: test
	@echo all: complete

test: test.o Vector.o
	$(CC) -Wall -o $@ $^

test.o: test.cpp test.h
	$(CC) -Wall -c -o $@ test.cpp

Vector.o: Vector.cpp Vector.h
	$(CC) -Wall -c -o $@ Vector.cpp

clean:
	rm test.o Vector.o test

run: test
	@./$^
