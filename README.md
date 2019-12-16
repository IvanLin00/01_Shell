# 01_Shell

Shell
by Ivan Lin and Jimmy Luo

Features:
  + Forks and executes commands
  + Runs multiple commands using ;
  + Redirects using >

Attempted:
  + Pipes do not work
  + Attempted to implement < but doesn't work

Bugs:
  + Putting spaces in when using ; will not work (No spaces between commands and semicolons)
   + Example: ls;ps works but ls ; ps doesn't work
  + Putting spaces in when using > will not work (No spaces between commands and >)
   + Example: w>wholist works but w > wholist doesn't work
  + Exit sometimes doesn't work when multiple commands are run
  + The file created after redirection has to be removed

Files & Function Headers:
parse.c
  + Parses commands from command line

  + char ** parse_args
  + Inputs: char * line, char * parse
  + Returns: A string array with the line parsed by parse

redirection.c
  + Runs the redirection commands

  + void run_in
  + Inputs: char * command
  + Runs the redirect command with '<'
  + Doesn't work

  + void run_out
  + Inputs: char * command
  + Runs the redirect command with '>'

  + int redir
  + Inputs: char * commandline
  + Returns: An int which indicates the redirection redirection

pipes.c
  + Runs the pipe commands (doesn't work)

  + int pipes_needed
  + Inputs: char * commandline
  + Returns: An int indicating if there is a pipes

  + void mario
  + Inputs: char * commandline
  + Runs the pipe commands (doesn't work)
