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
	  char **args = parse_args(commandline, "\n");
    char **s_args = parse_args(args[0], ";");
		int num_children = 0;
	  for(int i = 0; !(s_args[i] == NULL); i++){
	 	   num_children ++;
	  }
	  //not sure about order --> fork first or check for cd/exit first
	  //char **cargs = parse_args(commandline, " ")
 		// if (!strncmp(cargs[0], "exit", 100)){
		// 	exit(0);
		// }
		// if (!strncmp(cargs[0], "cd", 100)){
		//   chdir(cargs[1]);
		// }
    for(int i = 0; i < num_children; i++){
      char **cargs = parse_args(s_args[i], " ");
      printf("%s\n", cargs[0]);
      int f = fork();
      int *status;
      wait(status);
      if(!f) execvp(cargs[0], cargs);
    }
		// int ffs = fork();
		// int *status;
		// wait(status);
		// if(!ffs){
		//   execvp(cargs[0], cargs);
		// }
  }
}

//cd, exit, ;, redirection, pipes
//implement infinite loop

//parse by semi colon
//count how many there are
//parse by space for each thing in array
//make children (o-o)
//run commands :)
