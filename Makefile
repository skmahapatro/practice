CC=gcc
CFLAGS=-I.
OBJ = matrix.o

%.o: %.c
		$(CC) -c -o $@ $< $(CFLAGS)

matrix: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)
