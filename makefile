all: main.o parse.o redirection.o
	gcc -o shell main.o parse.o redirection.o

main.o: main.c parse.h
	gcc -c main.c

parse.o: parse.c parse.h
	gcc -c parse.c

redirection.o: redirection.c redirection.h
	gcc -c redirection.c

run:
	./shell "echo for forks sakes"

clean:
	rm *.o
	rm shell
