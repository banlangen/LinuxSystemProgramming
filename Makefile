.PHONY: all
CC = gcc 
FLAGS = -Wall -g
all : 01cp
01cp: 01cp.c
	$(CC) $(FLAGS)  $< -o $@
.PHONY: clean
clean :
	rm -rf *.o des.txt
