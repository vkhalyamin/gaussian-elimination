OBJMODULES = io.o gauss.o
CFLAGS = -g -Wall
CC = gcc

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

gauss: main.c $(OBJMODULES) 
	$(CC) $(CFLAGS) $^ -o $@

run: gauss
	./gauss

clean:
	rm -f *.o gauss
