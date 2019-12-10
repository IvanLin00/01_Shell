#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "parse.h"

int main(int argc, char *argv[]){
  char *commandline = argv[1];
	char **args = parse_args(commandline);
  if (!strncmp(args[0], "cd", 100)  || !strncmp(args[0], "exit", 100)){
    printf("%s\n",*args);
    int stuff = chdir(args[1]);
    printf("error number: %d %s\n", errno, strerror(errno));
    return 0;
  }
  int ffs = fork();
  int *status;
  wait(status);
  if(!ffs){
    execvp(args[0], args);
  }
  int num_children = 1 + count_semi(args);
  for(int num_forks = 0; num_forks < num_children; num_forks++){
    int p = fork();
    if(!p) break;
  }
  execvp(args[0], args);
  printf("hi\n");
  return 0;
}

//cd, exit, ;, redirection, pipes
//implement infinite loop

//parse by semi colon
//count how many there are
//parse by space for each thing in array
//make children (o-o)
//run commands :)
