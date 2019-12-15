#include <stdlib.h>
#include <stdio.h>

int redirection(char * commandline){
  for(int i = 0; i < sizeof(commandline); i++){
    if(commandline[i] == '>')
      return 1;
    if(commandline[i] == '<')
      return 2;
  }
  return 0;
}
