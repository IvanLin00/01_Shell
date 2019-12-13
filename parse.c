#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "parse.h"

// char ** parse_args(char * line){
// 	char *curr = line;
// 	char **tokens = malloc(5 * sizeof(char *));
// 	int i = 0;
// 	while(curr){
// 		tokens[i] = strsep(&curr, " ");
// 		i++;
// 	}
// 	return tokens;
// }

char ** parse_args(char * line, char * parse){
	char *curr = line;
	char **tokens = malloc(5 * sizeof(char *));
	int i = 0;
	while(curr){
		tokens[i] = strsep(&curr, parse);
		i++;
	}
	return tokens;
}

/* int count_semi(char ** commands){
	int count = 0;
	int i;
	for(i = 0; !(commands[i] == NULL); i ++){
		if (!strncmp(";",commands[i],100)){
			count ++;
		}
	}
	return count;
} */
