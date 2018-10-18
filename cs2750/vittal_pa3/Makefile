# Tarun Vittal
# cs2750 PA 3 
# 03/24/2018

CC=gcc
CFLAGS=-I. -std=c99
DEPS = avg.h sum.h max.h min.h
OBJ = main.o avg.o sum.o max.o min.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

statistics: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
