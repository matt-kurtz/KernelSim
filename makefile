CC = g++
CFLAGS = -ansi -Wall -g
SRCS = test.cpp queue.cpp process.cpp
OBJS = $(SRCS:.cpp=.o)

all: test

test: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o test

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f test $(OBJS)