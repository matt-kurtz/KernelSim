CC = g++
CFLAGS = -ansi -Wall -g
tgts = ksim.cpp process.cpp queue.cpp tokenizer.c functions.cpp

all: test

test: $(tgts)
	$(CC) $(CFLAGS) $(tgts) -o ksim

clean:
	rm %(tgts)