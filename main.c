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

  return 0;
}
