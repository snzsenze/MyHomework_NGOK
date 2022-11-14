CC = gcc
FLAGS = -Wall -Werror -Wextra

all: Array run

Array:
	@${CC} ${FLAGS} Array.c func.c -o Array

clean:
	@rm -rf *.out Array

run:
	@./Array

rebuild: clean Array run