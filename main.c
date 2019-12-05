#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parse.h"

int main(int argc, char *argv[]){
  char *commandline = argv[1];
	char **args = parse_args(commandline);
	printf("testing using ls -a -l\n");
  int ffs = fork();
  int *status;
  wait(status);
  if (args [0] == "cd" || args [0] == "exit"){

  }
  if(!ffs){
    execvp(args[0], args);
  }

  return 0;
}
