#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "parse.h"
#include "redirection.h"

int main(int argc, char *argv[]){
  while(1){
		printf("$");
	  char commandline[100];
	  fgets(commandline, 100, stdin);
    char **targs = parse_args(commandline, "\n");
    if(redirection(commandline) == 1){
      char **rargs = parse_args(commandline, ">");
    }
    if(redirection(commandline) == 2){
      char **rargs = parse_args(commandline, ">");
    }
	  char **args = parse_args(targs[0], ";");
		int num_children = 0;
	  for(int i = 0; !(args[i] == NULL); i++){
	 	  num_children ++;
	  }
    for(int i = 0;i < num_children; i++){
      char **cargs = parse_args(args[i], " ");
      if (!strncmp(cargs[0], "exit", 100)){
        exit(0);
      }
      if (!strncmp(cargs[0], "cd", 100)){
        chdir(cargs[1]);
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

//;, redirection, pipes
