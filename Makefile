.PHONY: all
CC = g++
FLAGS = -Wall -g
all : listdir 
listdir: listdir.cpp
	$(CC) $(FLAGS)  $< -o $@
.PHONY: clean
clean :
	rm -rf *.o des.txt
