CFLAGS=-g -Wall -Wextra -pedantic -Wformat=2

# Compiles and generates bin if needed
all: c 

# Compiles and makes bin if needed
c: src/main.c src/bat.c
	mkdir -p bin
	$(CC) -o bin/main src/main.c src/bat.c -lm

# run
r: bin/main
	bin/main

# compile and run
cr: all r

# run with a debugger
rd: all
	gdb bin/main

# compile and run with a debugger
crd: all rd

# Tell makefile that those arguments aren't files
.PHONY: all c r cr rd crd

