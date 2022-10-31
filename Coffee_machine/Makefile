CC = gcc
FLAGS = -Wall -Werror -Wextra

all: coffee_machine run

coffee_machine:
	@${CC} ${FLAGS} Coffee_machine.c func.c -o coffee_machine

clean:
	@rm -rf *.out coffee_machine

run:
	@./coffee_machine

rebuild: clean coffee_machine run