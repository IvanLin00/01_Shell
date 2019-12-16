all: main.o parse.o redirection.o pipes.o
	gcc -o shell main.o parse.o redirection.o pipes.o

main.o: main.c parse.h
	gcc -c main.c

parse.o: parse.c parse.h
	gcc -c parse.c

redirection.o: redirection.c redirection.h
	gcc -c redirection.c

pipes.o: pipes.c pipes.h
	gcc -c pipes.c

run:
	./shell "echo for forks sakes"

clean:
	rm *.o
	rm shell
