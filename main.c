#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "parse.h"

int main(int argc, char *argv[]){
  printf("%s\n", *argv[1]);
	char **args = parse_args(*argv);
	//printf("testing using ls -a -l\n");
	execvp(args[0], args);
  return 0;
}
