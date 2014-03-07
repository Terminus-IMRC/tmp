all: run

main: main.o

run: main
	./$<
