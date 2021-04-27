targets = main.bin test.bin
CC = gcc
C_OPTS = -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./library/src library/src/lib.c

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin test.bin

main.bin: project/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@ -lm
	
test.bin: library/test/test.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
	
test: clean prep compile
	./dist/test.bin
	
run: clean prep compile
	./dist/main.bin
	
doxygen:
	doxygen Doxyfile
	
format: #TODO

tidy: # TODO
