CC=gcc
CFLAGS=-I.
DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: shell

shell: main.o prompt.o
	$(CC) -o shell main.o prompt.o

clean:
	rm shell *.o
