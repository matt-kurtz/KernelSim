CC = g++
CFLAGS = -ansi -Wall -g
tgts = test.cpp process.cpp queue.cpp tokenizer.c functions.cpp

all: test

test: $(tgts)
	$(CC) $(CFLAGS) $(tgts) -o test

clean:
	rm %(tgts)