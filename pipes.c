#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "parse.h"
int pipes_needed(char * commandline){
  if(strchr(commandline, '|'))
    return 1;
  return 0;
}
// void mario(char * commandline){
//   char ** pargs = parse_args(commandline, "|");
//   char ** input = parse_args(pargs[0],"");
//   char ** output = parse_args(pargs[1],"");
//   int fds[2];
//   pipe(fds);
//   int ffs = fork();
//   if(!ffs){
//     int ffs2 = fork();
//     if(!ffs2){
//       dup2(fds[0], STDIN_FILENO);
//       execvp(input[0], input);
//       return;
//     }
//     else{
//       dup2(fds[1], STDOUT_FILENO);
//       execvp(output[1], output);
//       return;
//     }
//   }
// }
