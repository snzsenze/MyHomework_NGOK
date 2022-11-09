CC = gcc
FLAGS = -Wall -Werror -Wextra 



all: tetris

valgrind:
	@valgrind --leak-check=full --tool=memcheck ./tetris

tetris:
	@${CC} ${FLAGS} tetris.c func.c -o tetris -g 

clean:
	@rm -rf *.out tetris

testgdb:
	@gdb ./tetris

run:
	@./tetris

rebuild: clean tetris run