CC = gcc
FLAGS = -Wall -Werror -Wextra

all: tetris

tetris:
	@${CC} ${FLAGS} tetris.c func.c -lncurses -g -o tetris

valgrind:
	@valgrind --leak-check=full --tool=memcheck ./tetris

run:
	@./tetris

gdb:
	@gdb ./tetris

clean:
	@rm -rf tetris *.out .vscode/ 