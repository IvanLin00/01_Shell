#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "parse.h"

int main(int argc, char *argv[]){
  while(1){
		printf("$");
	  char commandline[100];
	  fgets(commandline, 100, stdin);
    char **targs = parse_args(commandline, "\n");
	  char **args = parse_args(targs[0], ";");
    printf("%s\n", targs[0]);
		int num_children = 0;
	  for(int i = 0; !(args[i] == NULL); i++){
	 	  num_children ++;
      printf("%d\n",num_children );
	  }
    for(int i = 0;i < num_children; i++){
      char **cargs = parse_args(args[i], " ");
      if (!strncmp(cargs[0], "exit", 100)){
        exit(0);
      }
      int ffs = fork();
  		int *status;
  		wait(status);
  		if(!ffs){
  		  execvp(cargs[0], cargs);
  		}
    }
}
}

//cd, exit, ;, redirection, pipes
//implement infinite loop

//parse by semi colon
//count how many there are
//parse by space for each thing in array
//make children (o-o)
//run commands :)
