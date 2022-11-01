CC = gcc
FLAGS = -Wall -Werror -Wextra

all: array run

array:
	@${CC} ${FLAGS} main.c func.c -o array

clean:
	@rm -rf *.out array

run:
	@./array

rebuild: clean array run
