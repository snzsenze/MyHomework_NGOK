CC = gcc
FLAGS = -Wall -Werror -Wextra



all: spiral

valgrind:
	@valgrind --leak-check=full --tool=memcheck ./matrix

spiral:
	@${CC} ${FLAGS} spiral.c func.c -o Spiral

clean:
	@rm -rf *.out spiral

run:
	@./spiral

rebuild: clean spiral run