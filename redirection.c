#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "parse.h"
#include "redirection.h"

void run_in (char * command){
  char ** commands = parse_args(command, "<");
  char ** b = parse_args(commands[0], " ");
  char ** args = parse_args(b[0], " ");
  char ** file_name = parse_args(commands[1], " ");
  int fd = open(*file_name, O_CREAT|O_EXCL|O_WRONLY|O_TRUNC, 0755);
  int f = fork();
  if(!f){
    dup2(fd, STDIN_FILENO);
    execvp(args[0], args);
    exit(0);
  }
  close(fd);
}

void run_out (char * command){
  char ** commands = parse_args(command, ">");
  char ** b = parse_args(commands[0], " ");
  char ** args = parse_args(b[0], " ");
  char ** file_name = parse_args(commands[1], " ");
  int fd = open(*file_name, O_CREAT|O_EXCL|O_WRONLY|O_TRUNC, 0755);
  int f = fork();
  if(!f){
    dup2(fd, STDOUT_FILENO);
    execvp(args[0], args);
    exit(0);
  }
  close(fd);
}

int redir(char * commandline){
  for(int i = 0; i < sizeof(commandline); i++){
    if(commandline[i] == '>')
      return 1;
    if(commandline[i] == '<')
      return 2;
  }
  return 0;
}
