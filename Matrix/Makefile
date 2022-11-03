CC = gcc
FLAGS = -Wall -Werror -Wextra



all: Matrix

valgrind:
	@valgrind --leak-check=full --tool=memcheck ./Matrix

Matrix:
	@${CC} ${FLAGS} Matrix.c func.c -o Matrix

clean:
	@rm -rf *.out Matrix

run:
	@./Matrix

rebuild: clean Matrix run